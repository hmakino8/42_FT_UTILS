/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:27:00 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/07 01:19:04 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cat_len;

	src_len = ft_strlen(src);
	if (dst == NULL)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	cat_len = (dstsize - 1) - dst_len;
	if (cat_len > src_len)
		cat_len = src_len;
	ft_strlcpy(&dst[dst_len], src, cat_len + 1);
	return (dst_len + src_len);
}
