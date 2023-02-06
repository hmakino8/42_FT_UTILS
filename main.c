#include "include/libft.h"
#include <libc.h>

int main(void)
{
	size_t	i;
	size_t	len;
	char	str1[0xF] = "nyan !";
	char	*str2 = "oh no not the empty string !";
	char	*str3 = "hello, I'm a data";
	char 	**dptr;
	t_list	*lst;

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
	printf("split test=========================\n");
	dptr = ft_split("split this for me", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("     split   this for   me  !  ", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("split  || this|for|me|||||!|", '|');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("                ", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("              olol", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("olol              ", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("", '\65');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("0 0 0 0 0 0 0 0", ' ');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);

	dptr = ft_split("\0aa\0bbb", '\0');
	len = ft_strlen_dptr(dptr);
	i = -1;
	while (++i < len)
		printf("elem[%zu] = %s\n", i, dptr[i]);
	ft_free_dptr((void **)dptr, len);
	printf("lstnew test=========================\n");
	write(2, "", 1);
	lst = ft_lstnew(str3);
	printf("[%s]\n", (char *)lst->content);
	printf("is correct? = %d\n", !strcmp(str3, lst->content));
	free(lst);
	printf("lstsize test=========================\n");
	lst = ft_lstnew(strdup("1"));
	lst->next = ft_lstnew(strdup("2"));
	lst->next->next = ft_lstnew(strdup("3"));
	printf("size = %d\n", ft_lstsize(lst));
	printf("lstadd_back test=========================\n");
	ft_lstadd_back(&lst, ft_lstnew("hello"));
	printf("size = %d\n", ft_lstsize(lst));
	printf("node(4) = %s\n", (char *)ft_lstlast(lst)->content);
}
