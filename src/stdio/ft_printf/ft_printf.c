/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/06 18:59:07 by hiroaki          ###   ########.fr       */
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

static int	creat_fd(int *fd)
{
	int			e;
	struct stat	st;

	stat(BUF, &st);
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

bool 	is_overflow(size_t	len)
{
	if (len > (size_t) INT_MAX)
	{
		errno = EOVERFLOW;
			return (true);
	}
	return (false);
}

ssize_t	internal_printf(int *fd, const char *fmt, va_list ap)
{
	ssize_t	bufsize;
	t_info	info;

	if (creat_fd(fd) < 0)
		return (-1);
	bufsize = 0;
	while (*fmt)
	{
		init_info(&info);
		if (*fmt != '%')
			bufsize += ft_putchar_fd(*fmt, *fd);
		else if (*fmt)
		{
			fmt++;
			fmt = parse_flag(fmt, &info);
			fmt = parse_width_prec(ap, fmt, &info);
			fmt = parse_spec(ap, fmt, &info);
			bufsize += process_spec(ap, *fd, &info);
		}
		fmt++;
		if (is_overflow(bufsize))
			return (EOF);
	}
	return (bufsize);
}

int ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int 	buf_fd;
	int		done;
	char	*buf;

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
		ft_free(buf);
	}
	if (unlink(BUF) < 0 || close(buf_fd) < 0 || errno == ENOMEM)
		return (EOF);
	return (done);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		done;

	va_start(ap, fmt);
	done = ft_vdprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (done);
}

int 	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		done;

	va_start(ap, fmt);
	done = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (done);
}
