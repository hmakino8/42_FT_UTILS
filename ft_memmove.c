/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:47:30 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/30 16:19:38 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	s1 = (char *)dst;
	s2 = (const char *)src;
	while (len--)
		s1[len] = s2[len];
	return (dst);
}
