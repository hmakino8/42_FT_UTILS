/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:28:39 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/02 23:39:47 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			loc;
	int			sig;
	char		*line;
	static char	*stk[OPEN_MAX];

	line = NULL;
	sig = NORMAL;
	if (validation(BUFFER_SIZE, fd) < 0 ||
		search_line_feed(&stk[fd], fd, &loc, &sig) < 0 ||
		split_buffer(&stk[fd], &line, loc) < 0)
		return (NULL);
	if (sig == END_OF_FILE)
		return (get_last_line(stk, &line, fd));
	return (line);
}

static int	validation(int bufsize, int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || OPEN_MAX < fd)
		return (-1);
	return (0);
}

static int	search_line_feed(char **stk, int fd, int *loc, int *sig)
{
	char	*tmp;

	if (*stk == NULL)
		*stk = ft_strdup("");
	if (*stk == NULL)
		return (-1);
	*loc = 0;
	while (*loc == 0 && *sig == NORMAL)
	{
		tmp = ft_strchr(*stk, '\n');
		if (tmp == NULL)
		{
			if (load_buffer(stk, fd, sig) < 0)
				return (-1);
		}
		else
			*loc = tmp - *stk + 1;
	}
	return (0);
}

static int	split_buffer(char **stk, char **line, int loc)
{
	size_t	len;
	char	*tmp;

	if (loc == 0)
		return (0);
	*line = ft_substr(*stk, 0, loc);
	if (*line == NULL)
		return (free_error_exit(*stk));
	len = ft_strlen(*stk) - loc;
	tmp = ft_substr(*stk, loc, len);
	free(*stk);
	if (tmp == NULL)
		return (-1);
	*stk = tmp;
	return (0);
}

static char	*get_last_line(char **stk, char **line, int fd)
{
	if (stk[fd] != NULL && *stk[fd] == '\0')
		;
	else
		*line = ft_strdup(stk[fd]);
	free(stk[fd]);
	return (*line);
}
