/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:33:46 by hmakino           #+#    #+#             */
/*   Updated: 2023/01/31 00:04:09 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	ch1;

	ch1 = (char)ch;
	i = 0;
	while (str[i] != '\0' || (str[i] == '\0' && ch1 == '\0'))
	{
		if (str[i] == ch1)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
