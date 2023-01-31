/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:30:17 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 19:28:17 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_free_dptr(void **dptr, size_t n)
{
	size_t	i;

	i = 0;
	if (dptr == NULL)
		return (NULL);
	while (i < n)
	{
		free(dptr[i]);
		dptr[i] = NULL;
		i++;
	}
	free(dptr);
	dptr = NULL;
	return (NULL);
}
