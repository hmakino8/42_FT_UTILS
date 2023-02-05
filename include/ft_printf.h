/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:34:07 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/05 15:56:52 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/stat.h>
# include "ft_stdio.h"
# include "ft_stdlib.h"
# include "get_next_line.h"

# define BUF "./.temp_buffer"

typedef enum s_printf_flag
{
	ZERO = (1 << 0),
	ALIGN = (1 << 1),
	PLUS = (1 << 2),
	SPACE = (1 << 3),
	SHARP = (1 << 4),
	HAS_WIDTH = (1 << 5),
	HAS_PREC = (1 << 6),
	HAS_SPEC = (1 << 7),
	SPEC_C = (1 << 8),
	SPEC_S = (1 << 9),
	SPEC_PCT = (1 << 10),
	SPEC_IDPUX = (1 << 11),
	IS_NEGATIVE = (1 << 12),
	PADDING_SPACE = (1 << 13)
}	t_flag;

typedef struct s_printf_info
{
	int				width;
	int				prec;
	int				spec;
	int				base;
	int				sign;
	unsigned int	bitflag;
	size_t			width_len;
	size_t			prec_len;
	size_t			len;
}	t_info;

/* ft_printf.c */
int				ft_printf(const char *fmt, ...);
/* ft_vdprintf.c */
int				ft_vdprintf(int fd, const char *fmt, va_list arg);
/* ft_dprintf.c */
int				ft_dprintf(int fd, const char *fmt, ...);
/* internal_printf.c */
int				internal_printf(int *fd, const char *fmt, va_list arg);
/* parse_fmt.c */
const char *parse_flag(const char *fmt, t_info *info);
const char *parse_width_precision(const char *fmt, t_info *info, va_list arg);
const char *parse_specific(const char *fmt, t_info *info, va_list arg);
/* process_specifer.c */
char	*specifier_idupx(va_list arg, t_info *info);
char	*specifier_percent_c(va_list ap, t_info *info);
char	*specifier_s(va_list arg, t_info *info);
/* write_to_fd.c */
ssize_t			buffering(int fd, t_info *info, va_list arg);
/* printf_helper.c */
bool			is_overflow(size_t len);
#endif
