/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:46:41 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 19:06:30 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_memchr(const void *vptr, int ch, size_t n)
{
	size_t				i;
	const unsigned char	*ustr;
	unsigned char		uch;

	ustr = (const unsigned char *)vptr;
	uch = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		if (ustr[i] == uch)
			return ((void *)&ustr[i]);
		i++;
	}
	return (NULL);
}
