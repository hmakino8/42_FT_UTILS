/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:57:09 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/02 01:33:37 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

ssize_t	ft_putstr(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
}

ssize_t	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return (-1);
	return (write(fd, str, ft_strlen(str)));
}
