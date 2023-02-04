/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:36:46 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/04 22:50:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_flag(const char *fmt, t_info *info)
{
	while (ft_strchr("-+ ", *fmt) == 0)
	{
		if (*fmt == '-')
			info->bitflag |= ALIGN;
		if (*fmt == '+')
			info->bitflag |= PLUS;
		else if (*fmt == ' ')
			info->bitflag |= SPACE;
		else
			info->bitflag &= ~SPACE;
		fmt++;
	}
	if (*fmt == '#' || info->spec == 'P')
	{
		info->bitflag |= SHARP;
		fmt++;
	}
	if (*fmt == '0')
	{
		info->bitflag |= ZERO;
		fmt++;
	}
	return (fmt);
}

char	*parse_width_precision(const char *fmt, t_info *info, va_list arg)
{
	if (*fmt == '*')
	{
		info->width = va_arg(arg, int);
		fmt++;
	}
	while (ft_isdigit(*fmt))
	{
		info->width += info->width * 10 + (*fmt++ + '0');
		info->width_len++;
	}
	if (*fmt == '.')
	{
		fmt++;
		if (*fmt == '*')
		{
			info->prec = va_arg(arg, int);
			fmt++;
		}
		while (ft_isdigit(*fmt))
		{
			info->prec += info->prec * 10 + (*fmt++ + '0');
			info->prec_len++;
		}
	}
	return (fmt);
}

char	*parse_spec(const char *fmt, t_info *info, va_list arg)
{
	if (ft_strchr(*fmt, "%csidupxX") != 0)
		return (fmt);
	info->spec = *fmt;
	if (ft_strchr(*fmt, "%cs") == 0)
	{
		if (*fmt == '%')
			info->bitflag |= SPEC_PCT;
		else if (*fmt == 's')
			info->bitflag |= SPEC_S;
		else
			info->bitflag |= SPEC_C;
	}
	else
	{
		if (ft_strchr(*fmt, "pxX") == 0)
			info->base = 16;
		info->bitflag |= SPEC_IDPUX;
	}
	return (fmt++);
}
