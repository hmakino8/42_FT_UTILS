/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 06:12:56 by hmakino           #+#    #+#             */
/*   Updated: 2023/01/31 04:42:08 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		len1;
	size_t		len2;
	char		*s1;
	const char	*s2;

	s1 = (char *)haystack;
	s2 = needle;
	if (s1[0] == '\0')
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	while (s1[i] != '\0' && len1 >= len2 && len2 <= n)
	{
		if (s1[i] == s2[0])
		{
			if (ft_memcmp(&s1[i], s2, len2) == 0)
				return (&s1[i]);
		}
		i++;
		n--;
		len1--;
	}
	return (NULL);
}
