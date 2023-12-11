/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:26 by dberreby          #+#    #+#             */
/*   Updated: 2023/12/11 16:55:22 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

// void	free_all(t_vars *game)
// {
// 	(void) game;
// 	if (game->img)
// 	{
// 		if (game->img->north_wall)
// 			mlx_destroy_image(game->mlx, game->img->north_wall);
// 		if (game->img->south_wall)
// 			mlx_destroy_image(game->mlx, game->img->south_wall);
// 		if (game->img->east_wall)
// 			mlx_destroy_image(game->mlx, game->img->east_wall);
// 		if (game->img->west_wall)
// 			mlx_destroy_image(game->mlx, game->img->west_wall);
// 		if (game->img->floor)
// 			free(game->img->floor);
// 		if (game->img->roof)
// 			free(game->img->roof);
// 		free(game->img);
// 	}
// 	if (game->win)
// 		mlx_destroy_window(game->mlx, game->win);
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		free(game->mlx);
// 	}
// 	if (game->map)
// 		free_map(game->map);
// }

void	free_all(t_vars *game)
{
	if (game->north_wall->img)
		mlx_destroy_image(game->mlx, game->north_wall->img);
	if (game->south_wall->img)
		mlx_destroy_image(game->mlx, game->south_wall->img);
	if (game->east_wall->img)
		mlx_destroy_image(game->mlx, game->east_wall->img);
	if (game->west_wall->img)
		mlx_destroy_image(game->mlx, game->west_wall->img);
	if (game->floor)
		free(game->floor);
	if (game->roof)
		free(game->roof);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
}

int	init_all(t_vars *game)
{
	game->rgb_floor = get_rgb(game->floor);
	game->rgb_ceiling = get_rgb(game->roof);
	return (1);
}

int	init_game(t_vars *game, char *filename)
{
	char	**file;

	if (!set_var_null(game))
		return (0);
	file = get_map(filename);
	if (!file)
		return (free_all(game), 0);
	if (!init_mlx(game))
		return (free_map(file), free_all(game), 0);
	if (!extract_textures(game, file))
		return (free_map(file), free_all(game), 0);
	if (!init_map(game, file))
		return (free_map(file), free_all(game), 0);
	if (!init_all(game))
		return (free_map(file), free_all(game), 0);
	return (free_map(file), 1);
}
