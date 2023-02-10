/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:36:17 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/09 19:21:35 by hiroaki          ###   ########.fr       */
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

typedef struct s_gnl_info
{
	int			fd;
	int			signal;
	ssize_t		byte;
	size_t		locate;
	char		*rtn_line;
	char		*buf;
}	t_gnl_info;

//get_next_line.c
char	*get_next_line(int fd);
int		locate_line_feed(char **stock, t_gnl_info *i);
void	load_buffer(char **stock, t_gnl_info *i);
void	joint_buffer(char **stock, t_gnl_info *i);
void	split_buffer(char **stock, t_gnl_info *i);
//get_next_line_utils.c
size_t	get_len(const char *s);
char	*gnl_strchr(char *s, int c);
char	*gnl_substr(char const *s, size_t start, size_t len, t_gnl_info *i);
char	*gnl_strjoin(char const *s1, char const *s2, t_gnl_info *i);

#endif
