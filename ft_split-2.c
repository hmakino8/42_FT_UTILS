/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:30:41 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/30 22:58:39 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static size_t	element_cnt(char const *str, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			cnt++;
			while (str[i] != c)
			{
				if (str[i] == '\0')
					return (cnt);
				i++;
			}
		}
		else
			i++;
	}
	return (cnt);
}

static char	\
	**element_cpy(char const *str, char **split, char c, size_t cnt)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (str[j] != '\0' && i < cnt)
	{
		len = 0;
		while (str[j] != '\0' && str[j] == c)
			j++;
		while (str[j + len] != '\0' && str[j + len] != c)
			len++;
		if (len != 0)
		{
			split[i] = ft_substr(&str[j], 0, len);
			if (split[i] == NULL)
				return ((char *)ft_free_dptr((void **)split, cnt));
			i++;
		}
		j += len;
	}
	return (split);
}

char	**ft_split(char const *str, char c)
{
	size_t	cnt;
	char	**split;

	if (str == NULL)
		return (str);
	cnt = element_cnt(str, c);
	split = malloc((cnt + 1) * sizeof(char *));
	if (split == NULL)
		return (split);
	split[cnt] = NULL;
	return (element_cpy(str, split, c, cnt));
}
