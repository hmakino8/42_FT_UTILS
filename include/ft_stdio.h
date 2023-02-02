/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:48:09 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/03 04:27:21 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>
# include "ft_string.h"

ssize_t ft_putchar(char ch);
ssize_t ft_putchar_fd(char ch, int fd);
ssize_t ft_putstr(char *str);
ssize_t ft_putstr_fd(char *str, int fd);
ssize_t ft_putendl_fd(char *str, int fd);
void ft_putnbr_fd(int c, int fd);

#endif
