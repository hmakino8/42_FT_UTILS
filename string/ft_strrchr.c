/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:37:42 by hmakino           #+#    #+#             */
/*   Updated: 2023/01/31 00:04:50 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;
	char	ch1;

	ch1 = (char)ch;
	len = ft_strlen(str);
	if (ch1 == '\0')
		return ((char *)&str[len]);
	while (len--)
	{
		if (str[len] == ch1)
			return ((char *)&str[len]);
	}
	return (NULL);
}
