# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 11:08:46 by jugingas          #+#    #+#              #
#    Updated: 2023/12/11 13:21:41 by dberreby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		src/cub.c						\
				src/coord_and_casting.c			\
				src/ft_game.c					\
				src/pars_map.c					\
				src/utils.c						\
				src/parsing_description.c		\
				src/parsing_description2.c 		\
				src/parsing_description3.c 		\
				src/parsing_description4.c 		\
				src/parsing_map.c 				\
				src/parsing_map2.c 				\
				src/parsing_map3.c 				\
				src/create_map.c 				\
				src/get_next_line.c 			\
				src/get_next_line_utils.c 		\
				src/init_game.c					\
				src/init_game2.c 				\
				src/init_game3.c 				\
				src/flood_fill.c				\
				src/flood_fill2.c

NAME		=	cub3D
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
