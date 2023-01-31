/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:48:09 by hmakino           #+#    #+#             */
/*   Updated: 2023/01/31 23:37:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "get_next_line.h"

# define BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct s_list {
	size_t			len;
	void			*content;
	struct s_list	*next;
}	t_list;

/* ctype */
int		ft_isalpha(int ch);
int		ft_isspace(int ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
/* string */
size_t	ft_strlen(const char *str);
size_t	ft_strlen_dptr(char **ptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_memcmp(const void *vptr1, const void *vptr2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *vptr, int ch, size_t n);
void	*ft_memset(void *vptr, int ch, size_t len);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	**ft_split(char const *str, char const *delim);
void	ft_bzero(void *s, size_t n);
/* stdlib */
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *src, size_t size);
void	*ft_xcalloc(size_t count, size_t size);
void	*ft_xmalloc(size_t size);
void	*ft_xrealloc(void *ptr, size_t size);
void	*ft_error_handler(char *funcname, int e);
void	*ft_free_dptr(void **dptr, size_t n);
int		ft_atoi(const char *str);
long	ft_strtol(const char *str, char **endptr, int base);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, int base);
/* stdio */
ssize_t	ft_putchar_fd(char ch, int fd);
ssize_t	ft_putstr_fd(char *str, int fd);
ssize_t	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int c, int fd);
/* linked-list */
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
