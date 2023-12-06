/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:26 by dberreby          #+#    #+#             */
/*   Updated: 2023/12/06 17:40:46 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_all(t_vars *game)
{
	if (game->img)
	{
		if (game->img->north_wall)
			mlx_destroy_image(game->mlx, game->img->north_wall);
		if (game->img->south_wall)
			mlx_destroy_image(game->mlx, game->img->south_wall);
		if (game->img->east_wall)
			mlx_destroy_image(game->mlx, game->img->east_wall);
		if (game->img->west_wall)
			mlx_destroy_image(game->mlx, game->img->west_wall);
		if (game->img->floor)
			free(game->img->floor);
		if (game->img->roof)
			free(game->img->roof);
		free(game->img);
	}
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

// int	init_game(t_game *game, t_data *data)
// {
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (free(game), printf_error(ERROR_MLX));
// 	game->wind = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
// 	if (game->wind == 0)
// 		return (destroy_game(game), printf_error(ERROR_MLX));
// 	game->imgptr = malloc(sizeof(t_img));
// 	if (!game->imgptr)
// 		return (destroy_game(game), printf_error(ERROR_MLX));
// 	game->imgptr->img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
// 	if (!game->imgptr->img)
// 		return (destroy_game(game), printf_error(ERROR_MLX));
// 	game->imgptr->addr = mlx_get_data_addr(game->imgptr->img, \
// 	&game->imgptr->bits_per_pixel, \
// 	&game->imgptr->line_length, &game->imgptr->endian);
// 	if (set_textures(game, data))
// 		return (destroy_game(game), printf_error(ERROR_TEXT));
// 	if (set_persona(game, data))
// 		return (destroy_game(game), printf_error(ERROR_MALLOC));
// 	if (set_raycaster(game))
// 		return (destroy_game(game), printf_error(ERROR_MALLOC));
// 	game->rgb_floor = get_rgb(data->rgb_floor);
// 	game->rgb_ceiling = get_rgb(data->rgb_ceiling);
// 	return (0);
// }

int init_all(t_vars *game)
{
	game->img->img = mlx_new_image(game->mlx, 1080, 720);
	if (!game->img->img)
		return (0);
	game->img->addr = mlx_get_data_addr(game->img->img, \
	&game->img->bits_per_pixel, \
	&game->img->line_length, &game->img->endian);
	game->rgb_floor = get_rgb(game->img->floor);
	game->rgb_ceiling = get_rgb(game->img->roof);
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
