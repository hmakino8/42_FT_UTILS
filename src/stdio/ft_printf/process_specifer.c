/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specifer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:03:13 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/05 21:41:22 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

char	*specifier_percent_c(va_list arg, t_info *info)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (info->bitflag & SPEC_PCT)
		str[0] = '%';
	else
		str[0] = va_arg(arg, int);
	info->len = 1;
	if (info->width > 0)
		info->width -= info->len;
	return (str);
}

char	*specifier_s(va_list arg, t_info *info)
{
	char	*str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = (char *)"(null)";
	if (!(info->prec_len == 1 && info->prec == 0))
		info->len = ft_strlen(str);
	if (is_overflow(info->len))
		return (NULL);
	if (info->prec_len > 0 && info->prec < info->len)
		info->len = info->prec;
	if (info->width)
		info->width -= (int)info->len;
	return (ft_strdup((char *)str));
}

static char *joint_prefix(char *str, char spec)
{
	char *tmp;
	char *prefix;

	if (str == NULL)
		return (NULL);
	tmp = str;
	if (spec == 'X')
		str = ft_strjoin("0X", str);
	else
		str = ft_strjoin("0x", str);
	ft_free(tmp);
	return (str);
}

static char \
	*conv_to_str(char *str, va_list arg, t_info *info)
{
	if (info->spec == 'u')
		str = ft_itoa_base(va_arg(arg, unsigned int), info->base);
	else if (info->spec == 'i' || info->spec == 'd')
	{
		str = ft_itoa_base(va_arg(arg, int), info->base);
		if (str[0] == '-')
		{
			info->len--;
			info->sign = '-';
			info->bitflag &= ~PLUS;
		}
		else if (info->bitflag & PLUS)
			info->sign = '+';
	}
	else
	{
		if (info->spec == 'P')
			str = ft_itoa_base(va_arg(arg, unsigned long), info->base);
		else
			str = ft_itoa_base(va_arg(arg, unsigned int), info->base);
		str = joint_prefix(str, info->spec);
	}
	return (str);
}

char	*specifier_idupx(va_list arg, t_info *info)
{
	unsigned int	*bit;
	char			*str;

	str = conv_to_str(str, arg, info);
	bit = &info->bitflag;
	if (str == NULL)
		return (NULL);
	info->len = ft_strlen(str);
	if (*bit & ZERO && (info->prec_len > 0 || *bit & ALIGN))
		*bit &= ~ZERO;
	if (*str == '0' && info->prec_len == 1 && info->prec == 0)
		info->len = 0;
	if (info->width > 0)
	{
		info->width -= (*bit & (SPACE & ZERO)) > 0;
		if (info->prec > 0 && info->len < info->prec)
			info->width -= (int)info->prec;
		else
			info->width -= (int)info->len;
	}
	if (info->len < info->prec)
		info->prec -= info->len;
	return (str);
}
