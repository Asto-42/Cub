# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 11:08:46 by jugingas          #+#    #+#              #
#    Updated: 2023/10/26 15:15:49 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		src/cub.c						\
				src/coord_and_casting.c			\
				src/ft_game.c					\
				src/pars_map.c					\
				src/utils.c						\
				src/get_next_line_bonus.c		\
				src/get_next_line_utils_bonus.c	\

NAME		=	cub3d
OBJS		=	$(SRC:.c=.o)
LIBS		=	-Lmlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -llibft
CC			=	cc
FLAGS		=	-g3 -Werror -Wextra -Wall -I include

#------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	make -C libft
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	make -C libft fclean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

#------------------------------------------------------------------

.PHONY: clean fclean re
