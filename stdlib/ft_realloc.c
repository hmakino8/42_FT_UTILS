/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:45:05 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 19:19:06 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*dst;

	if (size == 0)
	{
		free(src);
		return (ft_strdup(""));
	}
	if (src == NULL)
		return (malloc(size));
	dst = malloc(size);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, size);
	free(src);
	return (dst);
}
