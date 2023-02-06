/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:34:07 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/06 02:06:18 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <errno.h>
# include <sys/fcntl.h>
# include <sys/stat.h>
# include "../../../include/libft.h"

#define BUF "./printf_temp_buf"

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
}		t_info;

//ft_printf.c
int				ft_printf(const char *fmt, ...);
void			init_info(t_info *info);
//output.c
size_t 			process_spec(va_list ap, int fd, t_info *info);
//scrape.c
const char		*parse_flag(const char *fmt, t_info *info);
const char		*parse_width_prec(va_list ap, const char *fmt, t_info *info);
const char		*parse_spec(va_list ap, const char *fmt, t_info *info);
//utils.c
unsigned long	is_neg(int n, t_info *info);
char			*printf_itoa_base(unsigned long num, t_info *info);

#endif
