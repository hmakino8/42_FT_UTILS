/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:30:17 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 02:03:20 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

int	free_error_exit(char *str)
{
	ft_free(str);
	return (-1);
}

void	*ft_free(void *vptr)
{
	free(vptr);
	vptr = NULL;
	return (NULL);
}

void	*ft_free_dptr(void **dptr, size_t n)
{
	size_t	i;

	i = 0;
	if (dptr == NULL)
		return (NULL);
	while (i < n)
	{
		ft_free(dptr[i]);
		i++;
	}
	return (ft_free(dptr));
}
