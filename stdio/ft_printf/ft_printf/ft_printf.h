/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:34:07 by hmakino           #+#    #+#             */
/*   Updated: 2022/04/12 15:33:41 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_info
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
}		t_info;

//ft_printf.c
int				ft_printf(const char *format, ...);
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
