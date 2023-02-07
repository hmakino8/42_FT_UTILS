/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:28:39 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 01:11:49 by hiroaki          ###   ########.fr       */
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
	if (BUFFER_SIZE <= 0 || fd < 0 || OPEN_MAX < fd ||
		search_line_feed(&stk[fd], fd, &loc, &sig) < 0 ||
		split_buffer(&stk[fd], &line, loc) < 0)
		return (NULL);
	if (sig == END_OF_FILE)
	{
		if (!(stk[fd] != NULL && *stk[fd] == '\0'))
			line = ft_substr(stk[fd], 0, ft_strlen(stk[fd]));
		free(stk[fd]);
		stk[fd] = NULL;
	}
	return (line);
}

int	joint_buffer(char **stk, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*stk, buf);
	free(*stk);
	free(buf);
	*stk = NULL;
	buf = NULL;
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
		free(buf);
		buf = NULL;
		if (byte < 0)
			return (free_error_exit(*stk));
		else
			*sig = END_OF_FILE;
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
	free(*stk);
	*stk =NULL;
	if (tmp == NULL)
		return (-1);
	*stk = tmp;
	return (0);
}

// #include <libc.h>
// #include <fcntl.h>
// #include <stdio.h>
//
//__attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
//
// int main(void)
//{
//	int fd;
//	char *line;
//
//	fd = open("./files/41_no_nl", O_RDONLY);
//	//fd = open("./files/41_with_nl", O_RDONLY);
//	//fd = open("./files/42_no_nl", O_RDONLY);
//	//fd = open("./files/42_with_nl", O_RDONLY);
//	//fd = open("./files/43_no_nl", O_RDONLY);
//	//fd = open("./files/43_with_nl", O_RDONLY);
//	//fd = open("./files/alternate_line_nl_no_nl", O_RDONLY);
//	//fd = open("./files/alternate_line_nl_with_nl", O_RDONLY);
//	//fd = open("./files/big_line_no_nl", O_RDONLY);
//	//fd = open("./files/big_line_with_nl", O_RDONLY);
//	//fd = open("./files/empty", O_RDONLY);
//	//fd = open("./files/multiple_line_no_nl", O_RDONLY);
//	//fd = open("./files/multiple_line_with_nl", O_RDONLY);
//	//fd = open("./files/multiple_nlx5", O_RDONLY);
//	//fd = open("./files/nl", O_RDONLY);
//
//	while (1)
//	{
//		line = get_next_line(fd);
//		//printf("%s",line);
//		if (line == NULL)
//			break ;
//		free (line);
//	}
//	return (0);
// }
