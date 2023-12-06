/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:42:47 by jquil             #+#    #+#             */
/*   Updated: 2023/12/06 15:48:26 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_keymove(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_clear_mlx(vars);
	printf("Keycode = %i\n", keycode);

			// deplacement //
	// 119 = W | 115 = S | 100 = D | 97 = A | gerer WA, WD, SD, SA ? -> pas mandatory mais facile
	// if (keycode == 119)
	// 	vars->map = ft_rework_map_move(vars->map, "up", vars);
	// if (keycode == 115)
	// 	vars->map = ft_rework_map_move(vars->map, "down", vars);
	// if (keycode == 100)
	// 	vars->map = ft_rework_map_move(vars->map, "right", vars);
	// if (keycode == 97)
	// 	vars->map = ft_rework_map_move(vars->map, "left", vars);

			// rotate pov //
	if (keycode == 101)
		vars->pos_p.rad += 10;
	if (keycode == 113)
		vars->pos_p.rad += -10;
	return (1);
}

int	ft_key_hook(t_vars *vars)
{
	ft_clear_mlx(vars);
	return (1);
}

t_vars	initialise_var(t_vars *vars)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	vars->pos_p.rad = 0;
	vars->pi = M_PI;
	vars->pos_p.sens = 1;
	return (*vars);
}

void	ft_game(t_vars *game)
{
	game->nb_line_map = ft_nb_line(game->map);
	game->size_line = ft_size_line(game->map, game->nb_line_map);
	define_pos_player(game);
	printf("ft_game\n");
	ft_ray_casting_rework(game);
	mlx_hook(game->win, 17, 0, ft_key_hook, game);
	mlx_hook(game->win, 2, 1L << 0, ft_keymove, game);
	//mlx_hook(vars.win, 6, 1L << 0, ft_keymove, &vars); -> mouvement de souris ?
	mlx_loop(game->mlx);
}
