# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 17:10:58 by hiroaki           #+#    #+#              #
#    Updated: 2023/02/10 16:37:36 by hiroaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a
CFLAGS			:=	-Wall -Wextra -Werror
INCLUDE			=	-I./include

OBJDIR			:=	obj

STDLIB			:=	src/stdlib/ft_atoi.c \
					src/stdlib/ft_calloc.c \
					src/stdlib/ft_free.c \
					src/stdlib/ft_itoa.c \
					src/stdlib/ft_itoa_base.c \
					src/stdlib/ft_realloc.c \
					src/stdlib/ft_strtol.c \
					src/stdlib/ft_xalloc.c

LINKEDLIST		:=	src/linkedlist/ft_lstadd_back.c \
					src/linkedlist/ft_lstadd_front.c \
					src/linkedlist/ft_lstclear.c \
					src/linkedlist/ft_lstdelone.c \
					src/linkedlist/ft_lstiter.c \
					src/linkedlist/ft_lstlast.c \
					src/linkedlist/ft_lstmap.c \
					src/linkedlist/ft_lstnew.c \
					src/linkedlist/ft_lstsize.c

STRING			:=	src/string/ft_bzero.c \
					src/string/ft_memchr.c \
					src/string/ft_memcmp.c \
					src/string/ft_memcpy.c \
					src/string/ft_memmove.c \
					src/string/ft_memset.c \
					src/string/ft_split.c \
					src/string/ft_strchr.c \
					src/string/ft_strdup.c \
					src/string/ft_striteri.c \
					src/string/ft_strjoin.c \
					src/string/ft_strlcat.c \
					src/string/ft_strlcpy.c \
					src/string/ft_strlen.c \
					src/string/ft_strmapi.c \
					src/string/ft_strncmp.c \
					src/string/ft_strnstr.c \
					src/string/ft_strrchr.c \
					src/string/ft_strtrim.c \
					src/string/ft_substr.c

CTYPE			:=	src/ctype/ft_isalnum.c \
					src/ctype/ft_isalpha.c \
					src/ctype/ft_isascii.c \
					src/ctype/ft_isdigit.c \
					src/ctype/ft_isprint.c \
					src/ctype/ft_isspace.c \
					src/ctype/ft_tolower.c \
					src/ctype/ft_toupper.c

STDIO			:=	src/stdio/ft_putchar_fd.c \
					src/stdio/ft_putendl_fd.c \
					src/stdio/ft_putnbr_fd.c \
					src/stdio/ft_putstr_fd.c \
					src/stdio/get_next_line/get_next_line.c \
					src/stdio/ft_printf/ft_printf.c \
					src/stdio/ft_printf/ft_dprintf.c \
					src/stdio/ft_printf/ft_vdprintf.c \
					src/stdio/ft_printf/internal_printf.c \
					src/stdio/ft_printf/ft_printf-parse.c \
					src/stdio/ft_printf/ft_printf-utils.c \
					src/stdio/ft_printf/ft_printf-buffering.c
					#src/stdio/get_next_line/get_next_line_utils.c \

SRCS			=	$(STDLIB) $(LINKEDLIST) $(STRING) $(CTYPE) $(STDIO)
OBJS			=	$(SRCS:%.c=$(OBJDIR)/%.o)
DEPS			=	$(OBJS:%.o=%.d)

all:	$(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(@D)
	@ar -r $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
