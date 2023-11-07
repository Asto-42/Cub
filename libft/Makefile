# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:52:59 by jquil             #+#    #+#              #
#    Updated: 2023/11/03 14:55:08 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_atoi.c		\
				ft_bzero.c		\
				ft_calloc.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_itoa.c		\
				ft_memcpy.c		\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_putchar_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c	\
				ft_split.c		\
				ft_strchr.c		\
				ft_strdup.c		\
				ft_striteri.c	\
				ft_strlcat.c	\
				ft_strlcpy.c	\
				ft_strlen.c		\
				ft_strmapi.c	\
				ft_strncmp.c	\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_strtrim.c	\
				ft_substr.c		\
				ft_tolower.c	\
				ft_toupper.c	\

BSRC		=	ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstnew.c			\
				ft_lstsize.c		\

OBJ			=	$(SRC:.c=.o)

BOBJ		= 	$(BSRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror

NAME		=	libft.a

all:	$(NAME)

$(NAME):  $(OBJ)
	cc -c $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:
	cc -c $(CFLAGS) $(SRC) $(BSRC)
	ar rc $(NAME) $(OBJ) $(BOBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
