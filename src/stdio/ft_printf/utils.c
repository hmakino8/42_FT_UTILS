/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:37:34 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/06 00:47:37 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	is_neg(int n, t_info *i)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		i->sign = '-';
	}
	return ((unsigned long)num);
}

static int	get_digit(unsigned long num, t_info *i)
{
	int	digit;

	if (i->sign != '-' && i->flag_plus)
		i->sign = '+';
	digit = 1;
	while (i->base <= num)
	{
		num /= i->base;
		digit++;
	}
	if ((num && ((i->flag_sharp && i->spec == 'x') || \
			(i->flag_sharp && i->spec == 'X'))) || i->spec == 'p')
		digit += 2;
	return (digit);
}

char	*printf_itoa_base(unsigned long num, t_info *i)
{
	int				len;
	char	*str;

	len = get_digit(num, i);
	str = calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len--)
	{
		str[len] = num % i->base + '0';
		if ('9' < str[len])
			str[len] = num % i->base - 10 + 'a';
		if ('9' < str[len] && i->spec == 'X')
			str[len] -= ('a' - 'A');
		num /= i->base;
		i->len++;
	}	
	if ((i->flag_sharp && i->spec == 'x') || i->spec == 'p')
		str[1] = 'x';
	if (i->flag_sharp && i->spec == 'X')
		str[1] = 'X';
	return (str);
}
