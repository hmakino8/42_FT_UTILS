/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:56:23 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/05 02:56:43 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_overflow(size_t len)
{
	if (len > (size_t) INT_MAX)
	{
		errno = EOVERFLOW;
		return (true);
	}
	return (false);
}
