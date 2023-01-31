/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:45:05 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 01:50:56 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	size;
	void	*ret;

	if (size == 0)
	{
		free(ptr);
		return (ft_strdup(""));
	}
	if (ptr == NULL)
		return (malloc(size));
	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, ptr, size);
	free(ptr);
	return (ret);
}
