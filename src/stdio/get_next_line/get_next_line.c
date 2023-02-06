/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:28:39 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/06 19:17:23 by hiroaki          ###   ########.fr       */
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
		if (*stk[fd] != '\0')
		{
			line = ft_strdup(stk[fd]);
			stk[fd] = NULL;
			return (line);
		}
		else
			return (NULL);
		//if (*stk[fd] == '\0')
		//	stk[fd] = NULL;
		//line = ft_strdup(stk[fd]);
		//stk[fd] = NULL;
	}
	return (line);
}
