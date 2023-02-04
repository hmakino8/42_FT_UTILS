/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specifer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:03:13 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/05 03:08:15 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*specifier_percent_c(va_list ap, t_info *info)
{
	unsigned char	*str;

	str = ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (info->bitflag & SPEC_PCT)
		str[0] = '%';
	else
		str[0] = va_arg(ap, int);
	if (info->width > 0)
		info->width -= 1;
	return (str);
}

unsigned char	*specifier_s(va_list arg, t_info *info)
{
	unsigned char	*str;

	str = va_arg(arg, unsigned char *);
	if (str == NULL)
		str = (unsigned char *)"(null)";
	if (!(info->prec_len == 1 && info->prec == 0))
		info->len = ft_strlen(str);
	if (is_overflow(info->len))
		return (NULL);
	if (info->prec_len > 0 && info->prec < info->len)
		info->len = info->prec;
	if (info->width)
		info->width -= (int)info->len;
	return ((unsigned char *)ft_strdup(str));
}

char *joint_prefix(char *str, char spec)
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

char *conv_to_str(char *str, va_list arg, t_info *info)
{
	if (info->spec == 'u')
		str = ft_itoa_base(va_arg(arg, unsigned int), info->base);
	else if (info->spec == 'i' || info->spec == 'd')
	{
		str = ft_itoa_base(va_arg(arg, int), info->base);
		if (str[0] == '-')
			info->sign = '-';
		else if (info->bitflag & PLUS)
			info->sign = '+';
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
	int				*flag;
	unsigned char	*str;

	flag = &info->bitflag;
	str = conv_to_str(str, arg, info);
	if (str == NULL)
		return (NULL);
	if ((*flag & ZERO) && (info->prec_len > 0 || (*flag & ALIGN)))
		*flag &= ~ZERO;
	if (*str == '0' && info->prec_len = 1 && info->prec == 0)
		i->len = 0;
	if (info->width > 0)
	{
		info->width -= (info->sign > 0) + (*flag & SPACE);
		if (info->prec > 0 && info->len < info->prec)
			info->width -= (int)info->prec;
		else
			info->width -= info->len;
	}
	if (info->len < info->prec)
		info->prec -= i->len;
	return (str);
}
