/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:34:07 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 19:26:55 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <errno.h>
# include <sys/fcntl.h>
# include <sys/stat.h>
# include <stdbool.h>
# include "ft_stdio.h"

# define BUF "./printf_temp_buf"

typedef struct s_printf_info
{
	int		width;
	int		spec;
	int		sign;
	int		digit_width;
	int		digit_prec;
	int		has_prec;
	int		spec_cs;
	int		flag_zero;
	int		flag_align;
	int		flag_plus;
	int		flag_space;
	int		flag_sharp;
	size_t	prec;
	size_t	base;
	size_t	len;
}	t_info;

/* ft_printf.c */
int				ft_printf(const char *fmt, ...);

/* ft_dprintf.c */
int				ft_dprintf(int fd, const char *fmt, ...);

/* ft_vdprintf.c */
int				ft_vdprintf(int fd, const char *fmt, va_list ap);

/* internal_printf.c */
ssize_t			internal_printf(int *fd, const char *fmt, va_list ap);

/* ft_printf-parse.c */
const char		*parse_flag(const char *fmt, t_info *info);
const char		*parse_width_prec(va_list ap, const char *fmt, t_info *info);
const char		*parse_spec(const char *fmt, t_info *info);

/* ft_printf-utils.c */
bool			is_overflow(size_t	len);
unsigned long	is_neg(int n, int *sign);
char			*printf_itoa_base(unsigned long num, t_info *info);

/* ft_printf-buffering.c */
size_t			buf_to_fd(va_list ap, int fd, size_t bufsize, t_info *info);

#endif
