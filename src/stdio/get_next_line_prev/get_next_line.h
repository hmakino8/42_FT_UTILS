/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:36:17 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/20 10:42:11 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define NORMAL 1
# define END_OF_FILE 0
# define ERROR -1
# define MALLOC_FAILURE -2

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_info
{
	int			fd;
	int			signal;
	ssize_t		byte;
	size_t		locate;
	char		*rtn_line;
	char		*buf;
}	t_info;

//get_next_line.c
char	*get_next_line(int fd);
void	locate_line_feed(char **stock, t_info *i);
void	load_buffer(char **stock, t_info *i);
void	joint_buffer(char **stock, t_info *i);
void	split_buffer(char **stock, t_info *i);
//get_next_line_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len, t_info *i);
char	*ft_strjoin(char const *s1, char const *s2, t_info *i);

#endif
