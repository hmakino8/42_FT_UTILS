/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:45:05 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 19:27:41 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void	*ft_error_handler(char *funcname, int e)
{
	errno = e;
	perror(funcname);
	exit(EXIT_FAILURE);
	return (0);
}

void	*ft_xcalloc(size_t count, size_t size)
{
	size_t	total;
	void	*vptr;

	vptr = ft_calloc(count, size);
	if (vptr == NULL)
		error_handler("ft_xcalloc", errno);
	return (vptr);
}

void	*ft_xmalloc(size_t size)
{
	void	*vptr;

	vptr = malloc(size);
	if (vptr == NULL)
		error_handler("ft_xmalloc", errno);
	return (vptr);
}

void	*ft_xrealloc(void *src, size_t size)
{
	size_t	size;
	void	*dst;

	if (src == NULL)
		return (ft_xmalloc(size));
	dst = ft_realloc(src, size);
	if (dst == NULL)
		error_handler("ft_xmalloc", errno);
	return (dst);
}
