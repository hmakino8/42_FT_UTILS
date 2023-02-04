/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:29:38 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/05 03:11:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	padding_char(int fd, int ch, int *cnt)
{
	ssize_t	len;

	len = 0;
	while (0 < (*cnt)--)
		len += ft_putchar_fd(ch, fd);
	return (len);
}

static int	*reparse_flag(int *flag, int sign)
{
	if (!(*flag & ALIGN) && !(*flag & ZERO))
		*flag &= PADDING_SPACE;
	if (*flag & SPACE)
	{
		if ((*flag & SPEC_C) || (*flag & SPEC_S) || sign > 0)
			*flag &= ~SPACE;
	}
	if ((*flag & ALIGN) || !(*flag & ZERO))
		*flag &= ~ZERO;
	return (flag);
}

static int	*min_ptr(int *spec, int *width)
{
	if (*spec < *width)
		return (spec);
	return (width);
}

static ssize_t	write_to_fd(int fd, unsigned char *str, t_info *info)
{
	int		*flag;
	ssize_t	len;

	len = 0;
	flag = reparse_flag(info->bitflag, info->sign);
	if (!(*flag & ALIGN) && !(*flag & ZERO))
		len += padding_char(fd, ' ', &info->width);
	if (*flag & SPACE)
		len += ft_putchar_fd(' ', fd);
	if (info->sign > 0)
		len += ft_putchar_fd(info->sign, fd);
	if ((*flag & ZERO) && (*flag & SPEC_IDPUX))
		len += padding_char(fd, '0', min_ptr(info->prec, info->width));
	while (0 < info->len--)
		ft_putchar_fd(*str++, fd);
	if (*flag & ALIGN)
	{
		if (*flag & ZERO)
			len += padding_char(fd, '0', &info->width);
		else
			len += padding_char(fd, ' ', &info->width);
	}
	return (len);
}

ssize_t	buffering(int fd, t_info *info, va_list arg)
{
	ssize_t	bufsize;

	unsigned char	*str;

	if (is_overflow(info->width_len) || is_overflow(info->prec_len))
		return (-1);
	if (info->bitflag & SPEC_C)
		str = specifier_percent_c(arg, info);
	if (info->bitflag & SPEC_S)
		str = specifier_s(arg, info);
	if (info->bitflag & SPEC_IDPUX)
		str = specifier_idupx(arg, info);
	if (str == NULL)
		return (-1);
	bufsize = write_to_fd(fd, str, info);
	ft_free(str);
	return (bufsize);
}
