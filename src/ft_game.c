/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:42:47 by jquil             #+#    #+#             */
/*   Updated: 2023/10/30 14:31:04 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_keymove(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 65307)
		ft_clear_mlx(vars);
	printf("Keycode = %i\n", keycode);
			// deplacement //
	// if (keycode == 119)
	// 	vars->map = ft_rework_map_move(vars->map, "up", vars);
	// if (keycode == 115)
	// 	vars->map = ft_rework_map_move(vars->map, "down", vars);
	// if (keycode == 100)
	// 	vars->map = ft_rework_map_move(vars->map, "right", vars);
	// if (keycode == 97)
	// 	vars->map = ft_rework_map_move(vars->map, "left", vars);
			// rotate pov //
	//if (keycode == 101) -> E -> rotate right
	//if (keycode == 113) -> Q -> rotate left
	return (1);
}

int	ft_key_hook(t_vars *vars)
{
	ft_clear_mlx(vars);
	return (1);
}
t_vars	initialise_var(t_vars *vars)
{
	vars->win = NULL;
	vars->pos_p.rad = 0;
	vars->pi = M_PI;
	return (*vars);
}

int	ft_nb_line_empty(char *file)
{
	int		fd;
	int		nb_line;
	char	*r;

	fd = open(file, O_RDONLY);
	nb_line = 0;
	r = get_next_line(fd);
	while (r)
	{
		free(r);
		r = get_next_line(fd);
		nb_line++;
	}
	free (r);
	close (fd);
	return (nb_line);
}

char	**ft_extract_map_for_game(char *file)
{
	char	**map;
	int		fd;
	int		x;
	int		nb_line;

	x = 0;
	nb_line = ft_nb_line_empty(file) + 1;
	map = malloc ((nb_line + 1) * sizeof (char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (x < nb_line)
	{
		map[x] = get_next_line(fd);
		x++;
	}
	map[x] = NULL;
	close(fd);
	return (map);
}

void	ft_game(char *file)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_clear_mlx(&vars);
	vars = initialise_var(&vars);
	vars.map = ft_extract_map_for_game(file);
	if (vars.map == NULL)
		ft_clear_mlx(&vars);
	vars.nb_line_map = ft_nb_line(vars.map);
	vars.size_line = ft_size_line(vars.map, vars.nb_line_map);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "The adventure of Pjay vol.2");
	if (vars.win == NULL)
		ft_clear_mlx(&vars);
	define_pos_player(&vars);
	ft_ray_casting(&vars);
	mlx_hook(vars.win, 17, 0, ft_key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_keymove, &vars);
	//mlx_hook(vars.win, 6, 1L << 0, ft_keymove, &vars); -> mouvement de souris ?
	mlx_loop(vars.mlx);
}

//int mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color )
