/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:09:59 by jquil             #+#    #+#             */
/*   Updated: 2023/10/27 13:46:58 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct vector {
	float	x;
	float	y;
}	t_vector;

typedef struct pos_and_sens_player {
	float			x;
	float			y;
	char			sens;
	float			rad;
}				t_pasp;

typedef struct s_vars {
	void				*mlx;
	void				*win;
	char				**map;
	void				*img;
	int					nb_line_map;
	int					*size_line;
	long double			pi;
	t_pasp				pos_p;
}						t_vars;

typedef struct s_img {
	void	*p_s;
}				t_img;


//---- Parsing ---//
int		ft_extract_map_for_parse(char *file);
int		ft_keymove(int keycode, t_vars *vars);
int		ft_nb_line(char **map);
int		*ft_size_line(char **map, int nb_line);
void	ft_ray_casting(t_vars *vars);
void	define_pos_player(t_vars *vars);
int		ft_nb_line_empty(char *file);
void	free_map(char **map);
void	ft_clear_mlx(t_vars *vars);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_game(char *file);

#endif
