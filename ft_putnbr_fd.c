/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:54:21 by hmakino           #+#    #+#             */
/*   Updated: 2023/01/31 23:31:20 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		un = -n;
		ft_putchar_fd('-', fd);
	}
	else
		un = n;
	if (10 <= un)
		ft_putnbr_fd(un / 10, fd);
	ft_putchar_fd((char)(un % 10 + '0'), fd);
}
