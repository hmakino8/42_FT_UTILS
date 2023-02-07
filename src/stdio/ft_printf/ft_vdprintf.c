/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 02:39:51 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int 	buf_fd;
	int		done;
	char	*buf;

	buf = NULL;
	done = internal_printf(&buf_fd, fmt, ap);
	if (done < 0)
	{
		if (errno != EEXIST)
			unlink(BUF);
		close(buf_fd);
		return (EOF);
	}
	close(buf_fd);
	buf_fd = open(BUF, O_RDONLY);
	read(buf_fd, buf, done);
	while (1)
	{
		buf = get_next_line(buf_fd);
		if (buf == NULL)
			break ;
		done += ft_putstr_fd(buf, fd);
		ft_free((void **)&buf);
	}
	if (unlink(BUF) < 0 || close(buf_fd) < 0 || errno == ENOMEM)
		return (EOF);
	return (done);
}
