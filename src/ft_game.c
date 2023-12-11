/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:42:47 by jquil             #+#    #+#             */
/*   Updated: 2023/12/11 17:01:17 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rotate_pov(t_vars *vars, int keycode)
{
	// vars->pi / 32 de modif environ egal a 5.5 degre de mouvement par press, a voir
	if (keycode == 101)
		vars->pos_p.rad -= vars->pi / 32;
	else if (keycode == 113)
		vars->pos_p.rad += vars->pi / 32;
	if (vars->pos_p.rad > 2)
		vars->pos_p.rad -= 2;
	else if (vars->pos_p.rad < 0)
		vars->pos_p.rad += 2;
}

void	ft_move(t_vars *vars, int keycode)
{
	int	y = roundf(vars->pos_p.y);
	if (keycode == 119 && vars->pos_p.y <= vars->nb_line_map - 0.2) // W
		vars->pos_p.y += 0.2;
	else if (keycode == 115 && vars->pos_p.y >= 0.1) // S
		vars->pos_p.y -= 0.1;
	else if (keycode == 100 && vars->pos_p.x + 0.15 <= vars->size_line[y]) // D
		vars->pos_p.x += 0.15;
	else if (keycode == 97 && vars->pos_p.x >= 0.15) // A
		vars->pos_p.x -= 0.15;
}

int	ft_keymove(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_clear_mlx(vars);
	printf("Keycode = %i\n", keycode);
			// deplacement //
	// 119 = W | 115 = S | 100 = D | 97 = A
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
		ft_move(vars, keycode);
	if (keycode == 101 || keycode == 113) // 101 = E, 113 = Q
		ft_rotate_pov(vars, keycode);
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
	ft_ray_casting_rework(game);
	mlx_hook(game->win, 17, 0, ft_key_hook, game);
	mlx_hook(game->win, 2, 1L << 0, ft_keymove, game);
	//mlx_hook(vars.win, 6, 1L << 0, ft_keymove, &vars); -> mouvement de souris ?
	mlx_loop(game->mlx);
}
