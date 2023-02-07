/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfttest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:48:09 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/08 02:03:41 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdio.h>
#include "libft.h"

int main(void)
{
	size_t	i;
	size_t	len;
	char	str1[0xF] = "nyan !";
	char	*str2 = "oh no not the empty string !";
	char	*str3 = "hello, I'm a data";
	char	*str4 = "see FF your FF return FF now FF";
	char	*str5 = "FF";
	char	**dptr;
	t_list	*lst;

	/*
	 * SEGMENTATION FAULT TEST
	 *
	 * printf("ft : %zu\n", ft_strlcat(((void *)0), str1, 2));
	 * printf("org: %zu\n", strlcat(((void *)0), str1, 2));
	 *
	 * printf("ft : %s\n", ft_strnstr((void *)0, "fake", 3));
	 * printf("org: %s\n", strnstr((void *)0, "fake", 3));
	*/
	printf("strlcat test=========================\n");
	printf("ft : %zu\n", ft_strlcat(((void *)0), str1, 0));
	printf("org: %zu\n", strlcat(((void *)0), str1, 0));

	printf("strnstr test=========================\n");
	len = strlen(str2);
	printf("ft : %s\n", ft_strnstr("", str2, strlen(str2)));
	printf("org: %s\n", strnstr("", str2, strlen(str2)));
	printf("ft : %s\n", ft_strnstr(str2, "", strlen(str2)));
	printf("org: %s\n", strnstr(str2, "", strlen(str2)));
	printf("ft : %s\n", ft_strnstr(str2, "", 0));
	printf("org: %s\n", strnstr(str2, "", 0));
	printf("ft : %s\n", ft_strnstr(str4, str5, ft_strlen(str4)));
	printf("org: %s\n", strnstr(str4, str5, ft_strlen(str4)));
	printf("ft : %s\n", ft_strnstr((void *)0, "fake", 0));
	printf("org: %s\n", strnstr((void *)0, "fake", 0));

	printf("atoi test=========================\n");
	printf("ft : %d\n", ft_atoi("\t\v\f\r\n \f- \f\t\n\r    06050"));
	printf("org: %d\n", atoi("\t\v\f\r\n \f- \f\t\n\r    06050"));

	printf("split test=========================\n");
	dptr = ft_split("split this for me", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("     split   this for   me  !  ", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("split  || this|for|me|||||!|", '|');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("                ", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("              olol", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("olol              ", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("", '\65');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("0 0 0 0 0 0 0 0", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	dptr = ft_split("\0aa\0bbb", '\0');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void ***)&dptr, len);

	printf("lstnew test=========================\n");
	lst = ft_lstnew(strdup(str3));
	printf("[%s]\n", (char *)lst->content);
	printf("is correct? = %d\n", !strcmp(str3, lst->content));
	ft_lstclear(&lst, free);

	printf("lstsize test=========================\n");
	lst = ft_lstnew(strdup("1"));
	lst->next = ft_lstnew(strdup("2"));
	lst->next->next = ft_lstnew(strdup("3"));
	printf("size = %d\n", ft_lstsize(lst));

	printf("lstadd_back test=========================\n");
	ft_lstadd_back(&lst, ft_lstnew(strdup("hello")));
	printf("size = %d\n", ft_lstsize(lst));
	printf("node(4) = %s\n", (char *)ft_lstlast(lst)->content);
	ft_lstclear(&lst, free);

	return (0);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q libfttest");
}
