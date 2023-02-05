/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/05 17:07:17 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../../../include/ft_printf.h"
#include <sys/fcntl.h>

static void	init_info(t_info *info)
{
	info->width = 0;
	info->prec = 0;
	info->spec = 0;
	info->base = 10;
	info->sign = 0;
	info->bitflag = 0;
	info->len = 0;
	info->width_len = 0;
	info->prec_len = 0;
}

static int creat_fd(int *fd)
{
	int		e;
	struct	stat	statinfo;

	e = errno;
	stat(BUF, &statinfo);
	if (errno != ENOENT)
	{
		errno = EEXIST;
		return (-1);
	}
	errno = e;
	*fd = open(BUF, O_CREAT | O_RDWR, 0644);
	if (*fd < 0)
		return (-1);
	return (0);
}

int	internal_printf(int *fd, const char *fmt, va_list arg)
{
	ssize_t	bufsize;
	t_info	info;

	//if (creat_fd(fd) < 0)
	//	return (-1);
	*fd = 1;
	bufsize = 0;
	while (*fmt)
	{
		init_info(&info);
		if (*fmt != '%')
			bufsize += ft_putchar_fd(*fmt, *fd);
		else if (*fmt++)
		{
			fmt = parse_flag(fmt, &info);
			fmt = parse_width_precision(fmt, &info, arg);
			fmt = parse_specific(fmt, &info, arg);
			bufsize += buffering(*fd, &info, arg);
		}
		fmt++;
		if (is_overflow(bufsize))
			return (EOF);
	}
	return (0);
}
