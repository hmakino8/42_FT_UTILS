/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:45:05 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 03:55:20 by hiroaki          ###   ########.fr       */
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
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		error_handler("ft_xcalloc", ENOMEM);
	total = count * size;
	if (total == 0)
		total = 1;
	ptr = malloc(total);
	if (ptr == NULL)
		error_handler("ft_xcalloc", errno);
	ft_bzero(ptr, total);
	return (ptr);
}

void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		error_handler("ft_xmalloc", errno);
	return (ptr);
}

void	*ft_xrealloc(void *ptr, size_t size)
{
	size_t	size;
	void	*ret;

	if (ptr == NULL)
		return (ft_xmalloc(size));
	ret = ft_realloc(ptr, size);
	if (ret == NULL)
		error_handler("ft_xmalloc", errno);
	return (ret);
}
