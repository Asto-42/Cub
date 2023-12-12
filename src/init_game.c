/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:26 by dberreby          #+#    #+#             */
/*   Updated: 2023/12/12 17:49:39 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_all(t_vars *vars)
{
	if (vars->north_wall->img)
		mlx_destroy_image(vars->mlx, vars->north_wall->img);
	if (vars->south_wall->img)
		mlx_destroy_image(vars->mlx, vars->south_wall->img);
	if (vars->east_wall->img)
		mlx_destroy_image(vars->mlx, vars->east_wall->img);
	if (vars->west_wall->img)
		mlx_destroy_image(vars->mlx, vars->west_wall->img);
	if (vars->floor)
		free(vars->floor);
	if (vars->roof)
		free(vars->roof);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->map)
		free_map(vars->map);
}

int	init_all(t_vars *vars)
{
	vars->rgb_floor = get_rgb(vars->floor);
	vars->rgb_ceiling = get_rgb(vars->roof);
	vars->data->cur_time = 0;
	vars->data->old_time = 0;
	vars->data->texture = 0;
	return (1);
}

int	init_game(t_vars *vars, char *filename)
{
	char	**file;

	vars->win_x = 720;
	vars->win_y = 480;
	if (!set_var_null(vars))
		return (0);
	file = get_map(filename);
	if (!file)
		return (free_all(vars), 0);
	if (!init_mlx(vars))
		return (free_map(file), free_all(vars), 0);
	if (!extract_textures(vars, file))
		return (free_map(file), free_all(vars), 0);
	if (!init_map(vars, file))
		return (free_map(file), free_all(vars), 0);
	if (!init_all(vars))
		return (free_map(file), free_all(vars), 0);
	return (free_map(file), 1);
}
