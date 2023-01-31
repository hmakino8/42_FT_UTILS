/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:46:47 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 04:42:43 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	int					diff;
	unsigned const char	*us1;
	unsigned const char	*us2;

	us1 = (unsigned const char *)s1;
	us2 = (unsigned const char *)s2;
	i = 0;
	diff = 0;
	while (i < n)
	{
		diff = us1[i] - us2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
