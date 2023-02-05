/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/06 01:40:11 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->width = 0;
	info->prec = 0;
	info->spec = 0;
	info->spec_cs = 0;
	info->base = 10;
	info->sign = 0;
	info->digit_width = 0;
	info->digit_prec = 0;
	info->flag_zero = 0;
	info->flag_align = 0;
	info->flag_plus = 0;
	info->flag_space = 0;
	info->flag_sharp = 0;
	info->has_prec = 0;
	info->len = 0;
}

int	ft_printf(const char *fmt, ...)
{
	ssize_t	done;
	va_list	ap;
	t_info	info;

	va_start(ap, fmt);
	while (*fmt)
	{
		init_info(&info);
		if (*fmt != '%')
			ft_putchar_fd(*fmt, STDOUT_FILENO);
		else if (*fmt)
		{
			fmt++;
			fmt = parse_flag(fmt, &info);
			fmt = parse_width_prec(ap, fmt, &info);
			fmt = parse_spec(ap, fmt, &info);
			done += process_spec(ap, &info);
		}
		fmt++;
	}
	va_end(ap);
	return (0);
}
