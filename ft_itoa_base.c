/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:01:40 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 23:16:10 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdbool.h>

static int	digit_cnt(unsigned int un, int base)
{
	int	digit;

	digit = 1;
	while (base <= un)
	{
		un /= base;
		digit++;
	}
	return (digit);
}

static char	*make_array(unsigned int un, int len, int base, bool is_neg)
{
	int		i;
	char	*ptr;

	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = is_neg;
	while (len > i)
	{
		ptr[len - 1] = BASE[un % base];
		un /= base;
		len--;
	}
	if (is_neg)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa_base(int n, int base)
{
	int				len;
	unsigned int	un;
	bool			is_neg;

	is_neg = false;
	if (n < 0)
	{
		un = -n;
		is_neg = true;
	}
	else
		un = n;
	len = digit_cnt(un, base) + is_neg;
	return (make_array(un, len, base, is_neg));
}
