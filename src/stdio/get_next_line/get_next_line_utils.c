/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:14:19 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/06 19:17:32 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	joint_buffer(char **stk, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*stk, buf);
	ft_free(*stk);
	ft_free(buf);
	if (tmp == NULL)
		return (-1);
	*stk = tmp;
	return (0);
}

int	load_buffer(char **stk, int fd, int *sig)
{
	ssize_t	byte;
	char	*buf;

	buf = ft_calloc(BUFFER_SIZE + 1UL, sizeof(char));
	if (buf == NULL)
		return (free_error_exit(*stk));
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte <= 0)
	{
		ft_free(buf);
		if (byte < 0)
			return (free_error_exit(*stk));
		else
			*sig = END_OF_FILE;
		return (0);
	}
	return (joint_buffer(stk, buf));
}

int	search_line_feed(char **stk, int fd, int *loc, int *sig)
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
	ft_free(*stk);
	if (tmp == NULL)
		return (-1);
	*stk = tmp;
	return (0);
}
