/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:38:31 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/20 10:42:35 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (*us || (*us == '\0' && uc == '\0'))
	{
		if (*us == uc)
			return ((char *)us);
		us++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, size_t start, size_t len, t_info *i)
{
	size_t	idx;
	size_t	s_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen((char *)s);
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
	{
		i->signal = MALLOC_FAILURE;
		return (NULL);
	}
	idx = 0;
	while (s[start + idx] != '\0' && idx < len && start < s_len)
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2, t_info *i)
{
	size_t	idx;
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = NULL;
	if ((len_s1 / 2 + len_s2 / 2) + 1 < SIZE_MAX / 2)
		s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
	{
		i->signal = MALLOC_FAILURE;
		return (NULL);
	}
	idx = 0;
	while (*s1)
		s3[idx++] = *s1++;
	while (*s2)
		s3[idx++] = *s2++;
	s3[idx] = '\0';
	return (s3);
}
