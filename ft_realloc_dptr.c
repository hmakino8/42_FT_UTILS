/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_dptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:53:36 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 18:54:02 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdio.h>

void	**ft_realloc_dptr(void **dptr, void *ptr, size_t size)
{
	size_t	i;
	void	**ret;

	//if (size == 0 || !dptr)
	//	return (dptr);
	ret = malloc((size + 1) * sizeof(void *));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	if (!dptr[0])
	{
		ret[0] = ptr;
		return (ret);
	}
	i = 0;
	while (dptr[i] && i < size)
	{
		ret[i] = ft_strdup(dptr[i]);
		i++;
	}
	if (!ret[i])
		return (ret);
	ret[i] = ptr;
	//ft_free_dptr(dptr, ft_strlen_dptr((char **)dptr));
	return (ret);
}
