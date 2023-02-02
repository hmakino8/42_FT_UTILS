# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 17:10:58 by hiroaki           #+#    #+#              #
#    Updated: 2023/02/03 05:39:48 by hiroaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a
CFLAGS			:=	-Wall -Wextra -Werror -I./include

SRCDIR			:=	./src

STDLIB			:=	ft_atoi.c ft_calloc.c ft_free.c ft_itoa.c ft_itoa_base.c ft_realloc.c \
					ft_strtol.c ft_xalloc.c
STDLIBDIR		:=	$(SRCDIR)/stdlib/

LINKEDLIST		:=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
					ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
LINKEDLISTDIR	:=	$(SRCDIR)/linkedlist/

STRING			:=	ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
					ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
					ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
					ft_strtrim.c ft_substr.c
STRINGDIR		:=	$(SRCDIR)/string/

CTYPE			:=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
					ft_tolower.c ft_toupper.c
CTYPEDIR		:=	$(SRCDIR)/ctype/

GNLDIR			:=

STDIO			:=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
					get_next_line.c get_next_line_helper.c
STDIODIR		:=	$(SRCDIR)/stdio/

OBJDIR			:=	./obj
OBJS			:=	$(addprefix $(STDLIBDIR), $(notdir $(STDLIB:%.c=%.o))) \
					$(addprefix $(LINKEDLISTDIR), $(notdir $(LINKEDLIST:%.c=%.o))) \
					$(addprefix $(STRINGDIR), $(notdir $(STRING:%.c=%.o))) \
					$(addprefix $(CTYPEDIR), $(notdir $(CTYPE:%.c=%.o))) \
					$(addprefix $(STDIODIR), $(notdir $(STDIO:%.c=%.o))) \
					$(addprefix $(OBJS), $(notdir $(OBJS:%.c=%.o)))

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@-mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

all:	$(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
