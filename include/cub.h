/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:09:59 by jquil             #+#    #+#             */
/*   Updated: 2023/11/22 15:19:47 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct pos_and_sens_player
{
	double		x;
	double		y;
	char		sens;
	float		rad;
}				t_pasp;

typedef struct s_img
{
	void		*north_wall;
	void		*south_wall;
	void		*east_wall;
	void		*west_wall;
	void		*floor;
	void		*roof;
	int			*flooor;
	int			*rooof;
	char		*addr;
}				t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	int			nb_line_map;
	int			*size_line;
	long double	pi;
	t_pasp		pos_p;
	t_img		img;
}				t_vars;

//---- Parsing ---//

void			ft_ray_casting_rework(t_vars *vars);
int				ft_extract_map_for_parse(char *file);
int				ft_keymove(int keycode, t_vars *vars);
int				ft_nb_line(char **map);
int				*ft_size_line(char **map, int nb_line);
void			ft_ray_casting(t_vars *vars);
void			define_pos_player(t_vars *vars);
int				ft_nb_line_empty(char *file);
void			free_map(char **map);
void			ft_clear_mlx(t_vars *vars);
char			*ft_strjoin(char *s1, char *s2);
void			ft_game(char *file);

// parsing dav
int				check_textures(char **map, char **textures, int i, int *k);
int				char_is_desc_or_fc(char **map, int i, int k);
int				valid_description(char **map);
int				is_char_desc(char c, char d);
int				already_exist(char **textures, char **map, int i, int k);
int				get_image_name(char **map, char *str, int i, int k);
int				valid_image(char **map, int i, int k);
int				atoi(const char *str);
int				check_len_nb(char **map, int i, int *k, int *j);
int				skip_space(char **map, int i, int *k, int *nb_tour);
void			reset_k(char **map, int i, int *k);
int				valid_fc(char **map, int i, int k);
int				textures_good(char **textures);
char			**calloc_textures(void);
char			**init_textures(void);
void			update_textures(char **textures, char **map, int i);
int				line_walled(char *str);
int				space_walled(char **map, int i, int k);
int				is_walled(char **map);
int				valid_map(char **file);
int				valid_parsing(char *av);

// GNL dav
char			*get_line(char *full_line);
char			*reserve(char *full_line);
char			*get_full_line(int fd, char *full_line);
char			*get_next_line(int fd, int flag);
int				ft_strchr(char *s, char c);
char			*ft_strjoin(char *s1, char *s2);

#endif
