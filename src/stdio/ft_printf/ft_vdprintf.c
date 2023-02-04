/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/05 02:58:02 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, char *fmt, va_list arg)
{
	int		buf_fd;
	int		done;
	char	*buf;

	if (internal_printf(&buf_fd, fmt, arg) < 0)
		return (EOF);
	while (1)
	{
		buf = get_next_line(buf_fd);
		if (buf == NULL)
			break ;
		done += ft_putstr_fd(buf, fd);
	}
	if (close(fd) < 0 || unlink(BUF) < 0 || errno == ENOMEM)
		return (EOF);
	return (done);
}
