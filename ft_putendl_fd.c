/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:57:21 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/31 23:29:19 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

ssize_t	ft_putendl_fd(char *str, int fd)
{
	ssize_t	len;

	if (str == NULL)
		return (-1);
	len = ft_putstr_fd(str, fd);
	if (len > 0)
		len += ft_putchar_fd('\n', fd);
	return (len);
}
