/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/05 17:08:32 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	ft_vdprintf(int fd, const char *fmt, va_list arg)
{
	int		buf_fd;
	int		done;
	char	*buf;

	if (internal_printf(&buf_fd, fmt, arg) < 0)
	{
		if (errno != EEXIST)
			unlink(BUF);
		return (EOF);
	}
	//close(buf_fd);
	//buf_fd = open(BUF, O_RDONLY);
	//while (1)
	//{
	//	buf = get_next_line(buf_fd);
	//	if (buf == NULL)
	//		break ;
	//	done += ft_putstr_fd(buf, fd);
	//	ft_free(buf);
	//}
	unlink(BUF);
	//if (close(buf_fd) < 0 || errno == ENOMEM)
	//	return (EOF);
	return (done);
}
