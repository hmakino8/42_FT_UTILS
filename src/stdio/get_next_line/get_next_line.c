/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:28:39 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 16:06:49 by hiroaki          ###   ########.fr       */
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
	if (BUFFER_SIZE <= 0 || fd < 0 || OPEN_MAX < fd)
		return (NULL);
	if (search_line_feed(&stk[fd], &loc, &sig) < 0 ||
		creat_buffer(&stk[fd], fd, &sig) < 0 ||
		split_buffer(&stk[fd], &line, loc) < 0)
		return (NULL);
	if (sig == END_OF_FILE)
	{
		if (!(stk[fd] != NULL && *stk[fd] == '\0'))
			line = ft_strdup(stk[fd]);
		free(stk[fd]);
		stk[fd] = NULL;
	}
	return (line);
}

static char	*remove_null_char(char *buf, ssize_t byte)
{
	ssize_t	i;
	ssize_t	j;

	if (byte <= 0)
		return (buf);
	i = 0;
	j = 0;
	while (j < byte)
	{
		if (buf[j] == '\0')
			j++;
		buf[i] = buf[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	return (buf);
}

int	creat_buffer(char **stk, int fd, int *sig)
{
	ssize_t	byte;
	char	*buf;
	char	*tmp;

	buf = ft_calloc(BUFFER_SIZE + 1UL, sizeof(char));
	if (buf == NULL)
		return (free_error_exit(*stk));
	byte = read(fd, buf, BUFFER_SIZE);
	buf = remove_null_char(buf, byte);
	if (byte == 0)
		*sig = END_OF_FILE;
	if (byte < 0)
	{
		free(buf);
		free(*stk);
		return (-1);
	}
	tmp = ft_strjoin(*stk, buf);
	free(*stk);
	free(buf);
	*stk = NULL;
	if (tmp == NULL)
		return (-1);
	*stk = tmp;
	return (0);
}

int	search_line_feed(char **stk, int *loc, int *sig)
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
			break ;
		else
			*loc = tmp - *stk + 1;
	}
	return (0);
}

int	split_buffer(char **stk, char **line, int loc)
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
	*stk =NULL;
	if (tmp == NULL)
		return (-1);
	*stk = tmp;
	return (0);
}
