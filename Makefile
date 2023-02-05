# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 17:10:58 by hiroaki           #+#    #+#              #
#    Updated: 2023/02/05 23:23:36 by hiroaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a
CFLAGS			:=	-Wall -Wextra -Werror -I./include

SRCDIR			:=	./src
OBJDIR			:=	./obj

STDLIB			:=	ft_atoi.c ft_calloc.c ft_free.c ft_itoa.c ft_itoa_base.c ft_realloc.c \
					ft_strtol.c ft_xalloc.c
STDLIBDIR		:=	$(SRCDIR)/stdlib/
OBJS			:= 	$(addprefix $(STDLIBDIR), $(notdir $(STDLIB:%.c=%.o)))

LINKEDLIST		:=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
					ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
LINKEDLISTDIR	:=	$(SRCDIR)/linkedlist/
OBJS			+= 	$(addprefix $(LINKEDLISTDIR), $(notdir $(LINKEDLIST:%.c=%.o)))

STRING			:=	ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
					ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
					ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
					ft_strtrim.c ft_substr.c
STRINGDIR		:=	$(SRCDIR)/string/
OBJS			+=	$(addprefix $(STRINGDIR), $(notdir $(STRING:%.c=%.o)))

CTYPE			:=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
					ft_tolower.c ft_toupper.c
CTYPEDIR		:=	$(SRCDIR)/ctype/
OBJS			+=	$(addprefix $(CTYPEDIR), $(notdir $(CTYPE:%.c=%.o)))

STDIO			:=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STDIODIR		:=	$(SRCDIR)/stdio/
OBJS			+=	$(addprefix $(STDIODIR), $(notdir $(STDIO:%.c=%.o)))

all:	$(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@-mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
