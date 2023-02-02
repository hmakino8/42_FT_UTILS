/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:34:07 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/03 00:56:09 by hiroaki          ###   ########.fr       */
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

typedef enum s_printf_bitflag
{
	ZERO = (1 << 0),
	ALIGN = (1 << 1),
	PLUS = (1 << 2),
	SPACE = (1 << 3),
	SHARP = (1 << 4)
}	t_flag;

typedef struct s_printf_info
{
	int				width;
	int				spec;
	int				spec_cs;
	int				sign;
	int				digit_width;
	int				digit_prec;
	int				has_prec;
	int				check_overflow;
	bool			overflow;
	size_t			prec;
	size_t			base;
	size_t			idx;
	size_t			len;
	size_t			total_output;
	unsigned char	ch;
	t_flag			flag;
}	t_info;

//ft_printf.c
int				ft_printf(const char *fmt, ...);
void			initialize_info(t_info *i);
//output.c
void			output(unsigned char *args, t_info *i);
void			specifier_percent_c(va_list ap, t_info *i);
void			specifier_s(va_list ap, t_info *i);
void			specifier_idupx(va_list ap, t_info *i);
//scrape.c
void			scrape_hub(va_list ap, const char *s1, t_info *i);
//utils.c
int				ft_putchar(const unsigned char c, t_info *i);
int				ft_atoi(const char *s1, t_info *i);
int				ft_get_digit(unsigned long num, t_info *i);
unsigned long	is_neg(int n, t_info *i);
unsigned char	*ft_itoa_base(unsigned long num, t_info *i);

#endif
