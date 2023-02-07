/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:22:46 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/08 01:41:13 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <libc.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include "get_next_line.h"

 int main(void)
{
	int fd;
	char *line;

	printf("\nTEST1 ===============================\n");
	fd = open("./files/41_no_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST2 ===============================\n");
	fd = open("./files/41_with_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST3 ===============================\n");
	fd = open("./files/43_no_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST4 ===============================\n");
	fd = open("./files/43_with_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST5 ===============================\n");
	fd = open("./files/alternate_line_nl_no_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST6 ===============================\n");
	fd = open("./files/alternate_line_nl_with_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST7 ===============================\n");
	fd = open("./files/big_line_no_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST8 ===============================\n");
	fd = open("./files/big_line_with_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST9 ===============================\n");
	fd = open("./files/empty", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST10 ===============================\n");
	fd = open("./files/multiple_line_no_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST11 ===============================\n");
	fd = open("./files/multiple_line_with_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST12 ===============================\n");
	fd = open("./files/multiple_nlx5", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	printf("\nTEST13 ===============================\n");
	fd = open("./files/nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s",line);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);

	return (0);
 }

__attribute__((destructor))
 static void destructor() {
     system("leaks -q gnltest");
 }
