/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:13:24 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/02 01:39:57 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_printf_data
{
	int				width;
	int				spec;
	int				spec_cs;
	int				sign;
	int				digit_width;
	int				digit_prec;
	int				has_prec;
	int				flag_zero;
	int				flag_align;
	int				flag_plus;
	int				flag_space;
	int				flag_sharp;
	int				check_overflow;
	int				overflow;
	size_t			prec;
	size_t			base;
	size_t			idx;
	size_t			len;
	size_t			total_output;
	unsigned char	ch;
}	t_data;

/* ft_putchar_fd.c */
ssize_t			ft_putchar(char ch);
ssize_t			ft_putchar_fd(char ch, int fd);

/* ft_putstr_fd.c */
ssize_t			ft_putstr(char *str);
ssize_t			ft_putstr_fd(char *str, int fd);

/* ft_putendl_fd.c */
ssize_t			ft_putendl_fd(char *str, int fd);
ssize_t			ft_putendl_fd(char *str, int fd);

/* ft_putnbr_fd.c */
void			ft_putnbr_fd(int c, int fd);
void			ft_putnbr_fd(int c, int fd);

/* ft_printf/ft_printf.c */
int				ft_printf(const char *format, ...);
void			initialize_info(t_info *i);

/* ft_printf/utils/output.c */
void			output(unsigned char *args, t_info *i);
void			specifier_percent_c(va_list ap, t_info *i);
void			specifier_s(va_list ap, t_info *i);
void			specifier_idupx(va_list ap, t_info *i);

/* ft_printf/utils/scrape.c */
void			scrape_hub(va_list ap, const char *s1, t_info *i);

/* ft_printf/utils/utils.c */
int				ft_putchar(const unsigned char c, t_info *i);
int				ft_atoi(const char *s1, t_info *i);
int				ft_get_digit(unsigned long num, t_info *i);
unsigned long	is_neg(int n, t_info *i);
unsigned char	*ft_itoa_base(unsigned long num, t_info *i);

#endif
