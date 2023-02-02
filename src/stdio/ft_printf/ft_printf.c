/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/03 00:58:19 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	initialize_info(t_info *info)
{
	info->width = 0;
	info->prec = 0;
	info->spec = 0;
	info->spec_cs = 0;
	info->base = 10;
	info->sign = 0;
	info->digit_width = 0;
	info->digit_prec = 0;
	info->has_prec = 0;
	info->len = 0;
	info->ch = 0;
}

int	ft_vfprintf(FILE *stream, const char *fmt, va_list arg)
{

}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_info	info;

	info.check_overflow = 0;
	while (info.check_overflow < 2)
	{
		info.total_output = 0;
		info.overflow = 0;
		initialize_info(&info);
		va_start(ap, fmt);
		parse_hub(ap, fmt, &info);
		va_end(ap);
		if (info.overflow || (size_t)INT_MAX < info.total_output)
			return (-1);
		info.check_overflow++;
	}
	return ((int)info.total_output);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_info	info;

	info.check_overflow = 0;
	while (info.check_overflow < 2)
	{
		info.total_output = 0;
		info.overflow = 0;
		initialize_info(&info);
		va_start(ap, fmt);
		parse_hub(ap, fmt, &info);
		va_end(ap);
		if (info.overflow || (size_t)INT_MAX < info.total_output)
			return (-1);
		info.check_overflow++;
	}
	return ((int)info.total_output);
}
