/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:30:41 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 04:13:26 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static t_list	*add_lst(t_list **lst, char const *str, size_t len)
{
	t_list	*new;
	char	*tmp;

	tmp = ft_substr(str, 0, len);
	if (!tmp)
		return (NULL);
	new = ft_lstnew(tmp);
	if (!new)
		return (NULL);
	new->len = len;
	ft_lstadd_back(lst, new);
	return (*lst);
}

static t_list	*tokenize(t_list *lst, char const *str, char const *delim)
{
	size_t	len;
	size_t	dlen;
	char	*find;

	dlen = ft_strlen(delim);
	while (TRUE)
	{
		while (ft_strncmp(str, delim, dlen) == 0)
			str += dlen;
		len = ft_strlen(str);
		if (len == 0)
			break ;
		find = ft_strnstr(str, delim, len);
		if (find)
			len = find - str;
		if (!add_lst(&lst, str, len))
			return (NULL);
		if (!find)
			break ;
		str = find + dlen;
	}
	return (lst);
}

static char	**lst_to_dptr(t_list *lst, char **dptr, size_t n)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		dptr[i] = ft_strdup(lst->content);
		if (!dptr[i])
			return (ft_free_dptr((void **)dptr, n));
		i++;
		lst = lst->next;
	}
	return (dptr);
}

char	**ft_split(char const *str, char const *delim)
{
	size_t		n;
	char		**dptr;
	t_list		*lst;

	if (!str || !delim)
		return (NULL);
	lst = tokenize(NULL, str, delim);
	if (!lst)
		return (NULL);
	n = ft_lstsize(lst);
	dptr = malloc((n + 1) * sizeof(char *));
	if (dptr)
	{
		dptr[n] = NULL;
		dptr = lst_to_dptr(lst, dptr, n);
	}
	ft_lstclear(&lst, free);
	return (dptr);
}
