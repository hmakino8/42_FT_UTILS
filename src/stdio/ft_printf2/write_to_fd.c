/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:29:38 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/05 22:27:58 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static ssize_t	padding_char(int fd, int ch, int *cnt)
{
	ssize_t	len;

	len = 0;
	while (0 < (*cnt)--)
		len += ft_putchar_fd(ch, fd);
	return (len);
}

static unsigned int	*reparse_flag(unsigned int *flag, int sign)
{
	if (!(*flag & ALIGN) && !(*flag & ZERO))
		*flag &= PADDING_SPACE;
	if (*flag & SPACE)
	{
		if (*flag & (SPEC_C | SPEC_S) || sign > 0)
			*flag &= ~SPACE;
	}
	if (*flag & ALIGN || !(*flag & ZERO))
		*flag &= ~ZERO;
	return (flag);
}

static int	*min_ptr(int *spec, int *width)
{
	if (*spec < *width)
		return (spec);
	return (width);
}

static ssize_t	write_to_fd(int fd, char *str, t_info *info)
{
	unsigned int	flag;

	flag = info->bitflag;
	if (!(flag & ALIGN) && !(flag & ZERO))
	{
		while (0 < info->width--)
			ft_putchar_fd(' ', fd);
	}
	if (!(flag & SPEC_C) && !(flag & SPEC_S))
	{
		if (info->sign == 0 && flag & SPACE)
			ft_putchar_fd(' ', fd);
		if (info->sign > 0)
			ft_putchar_fd(info->sign, fd);
	}
	while ((flag & SPEC_IDPUX && 0 < info->prec--) || \
			(!(flag & ALIGN) && flag & ZERO && 0 < info->width--))
		ft_putchar_fd('0', fd);
	while (0 < info->len--)
	{
		if (*str == '-')
		{
			info->len--;
			str++;
		}
		ft_putchar_fd(*str++, fd);
	}
	while (flag & ALIGN && !(flag & ZERO) && 0 < info->width--)
		ft_putchar_fd(' ', fd);
	while (flag & ALIGN && flag & ZERO && info->width--)
		ft_putchar_fd('0', fd);
	return (0);
}

//static ssize_t	write_to_fd(int fd, char *str, t_info *info)
//{
//	unsigned int	*flag;
//	ssize_t			len;
//
//	len = 0;
//	//flag = reparse_flag(&info->bitflag, info->sign);
//	//if (!(*flag & ALIGN) && !(*flag & ZERO))
//	//	len += padding_char(fd, ' ', &info->width);
//	//if (*flag & SPACE)
//	//	len += ft_putchar_fd(' ', fd);
//	//if (*flag & PLUS)
//	//	len += ft_putchar_fd(info->sign, fd);
//	//if (*flag & (ZERO & SPEC_IDPUX))
//	//	len += padding_char(fd, '0', min_ptr(&info->prec, &info->width));
//	//while (*flag & SPEC_IDPUX && 0 < info->prec--)
//	//	ft_putchar_fd('0', fd);
//	while (!(*flag & ALIGN) && 0 < info->len--)
//		ft_putchar_fd(*str++, fd);
//	while (0 < info->width--)
//		ft_putchar_fd(' ', fd);
//	//while (0 < info->prec--)
//	//	ft_putchar_fd(' ', fd);
//	while (*flag & ALIGN && 0 < info->len--)
//		ft_putchar_fd(*str++, fd);
//	//if (*flag & ALIGN)
//	//{
//	//	if (*flag & ZERO)
//	//		len += padding_char(fd, '0', &info->width);
//	//	else
//	//		len += padding_char(fd, ' ', &info->width);
//	//}
//	return (len);
//}

ssize_t	buffering(int fd, t_info *info, va_list arg)
{
	ssize_t	bufsize;
	char	*str;

	if (is_overflow(info->width_len) || is_overflow(info->prec_len))
		return (-1);
	str = NULL;
	if (info->bitflag & (SPEC_C | SPEC_PCT))
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
