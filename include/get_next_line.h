/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:36:17 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/03 05:47:42 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include "ft_string.h"
# include "ft_stdlib.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define NORMAL 0
# define END_OF_FILE 1

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_helper.c */
int		joint_buffer(char **stk, char *buf);
int		load_buffer(char **stk, int fd, int *sig);
int		search_line_feed(char **stk, int fd, int *loc, int *sig);
int		split_buffer(char **stk, char **line, int loc);
char	*get_last_line(char **stk, char **line, int fd);

#endif
