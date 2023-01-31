/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:47:36 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/30 16:11:49 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ub;
	unsigned char	uc;

	ub = (unsigned char *)b;
	uc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ub[i] = uc;
		i++;
	}
	return (b);
}
