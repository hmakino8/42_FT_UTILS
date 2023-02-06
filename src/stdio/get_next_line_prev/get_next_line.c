/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:28:39 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/01 02:25:28 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock[OPEN_MAX];
	t_info		i;

	i.fd = fd;
	i.signal = NORMAL;
	i.rtn_line = NULL;
	locate_line_feed(&stock[i.fd], &i);
	split_buffer(&stock[i.fd], &i);
	if (i.signal == END_OF_FILE)
	{
		if (!(stock[i.fd] != NULL && *stock[i.fd] == '\0'))
			i.rtn_line = ft_substr(stock[i.fd], 0, ft_strlen(stock[i.fd]), &i);
		free(stock[i.fd]);
		stock[i.fd] = NULL;
	}
	return (i.rtn_line);
}

void	locate_line_feed(char **stock, t_info *i)
{
	char	*tmp;

	if (BUFFER_SIZE <= 0 || i->fd < 0 || OPEN_MAX < i->fd)
	{
		i->signal = ERROR;
		return ;
	}
	if (*stock == NULL)
		*stock = ft_substr("", 0, 0, i);
	if (i->signal == MALLOC_FAILURE)
		return ;
	i->locate = 0;
	while (i->locate == 0 && i->signal == NORMAL)
	{
		tmp = ft_strchr(*stock, '\n');
		if (tmp == NULL)
			load_buffer(stock, i);
		else
			i->locate = tmp - *stock + 1;
	}
}

void	load_buffer(char **stock, t_info *i)
{
	i->buf = (char *)malloc(BUFFER_SIZE + 1UL);
	if (i->buf == NULL)
	{
		i->signal = MALLOC_FAILURE;
		free (*stock);
		return ;
	}
	i->byte = read(i->fd, i->buf, BUFFER_SIZE);
	if (i->byte < 0)
	{
		i->signal = ERROR;
		free(*stock);
	}
	if (i->byte == 0)
		i->signal = END_OF_FILE;
	if (i->signal != NORMAL)
	{
		free(i->buf);
		i->buf = NULL;
	}
	else
		i->buf[i->byte] = '\0';
	joint_buffer(stock, i);
}

void	joint_buffer(char **stock, t_info *i)
{
	char	*tmp;

	if (i->signal != NORMAL)
		return ;
	tmp = ft_strjoin(*stock, i->buf, i);
	free(*stock);
	if (i->signal == MALLOC_FAILURE)
		return ;
	*stock = ft_substr(tmp, 0, ft_strlen(tmp), i);
	free(i->buf);
	i->buf = NULL;
	free(tmp);
}

void	split_buffer(char **stock, t_info *i)
{
	size_t	len;
	char	*tmp;

	if (i->locate == 0 || i->signal != NORMAL)
		return ;
	i->rtn_line = ft_substr(*stock, 0, i->locate, i);
	if (i->signal == MALLOC_FAILURE)
	{
		free(*stock);
		return ;
	}
	len = 0;
	len = ft_strlen(*stock) - i->locate;
	tmp = ft_substr(*stock, i->locate, len, i);
	free(*stock);
	if (i->signal == MALLOC_FAILURE)
		return ;
	*stock = ft_substr(tmp, 0, len, i);
	free(tmp);
}

//#include <libc.h>
//#include <fcntl.h>
//#include <stdio.h>
//
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}
//
//
//int main(void)
//{
//	char *line;
//	int fd;
//
//	//fd = open("./gnl_instructions.txt", O_RDONLY);
//	//fd = open("./file.txt", O_RDONLY);
//	//fd = open("./num_even.txt", O_RDONLY);
//	fd = open("./file.txt", O_RDONLY);
//	//fd = open("./41_with_nl", O_RDONLY);
//	//fd = open("./43_no_nl", O_RDONLY);
//	//line = ft_substr("", 0, 0);
//	//while (line)
//	//{
//	//	line = get_next_line(fd);
//	//	printf("line : %s", line);
//	//	free (line);
//	//}
//	//line = get_next_line(1000);
//	//printf("line : %s", line);
//	//free (line);
//	//line = get_next_line(-1);
//	//printf("line : %s", line);
//	//free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	line = get_next_line(fd);
//	printf("line : %s", line);
//	free (line);
//	return 0;
//}
