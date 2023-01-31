/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:34:53 by hmakino           #+#    #+#             */
/*   Updated: 2023/01/31 00:06:55 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(str);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, str, len + 1);
	return (ret);
}
