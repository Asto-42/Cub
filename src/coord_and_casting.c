/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/12/11 16:51:23 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int	next_x(t_vars *vars, int x, int y, t_vector vec)
// {
// 	int	param;

// 	while (x >= 0 && param >= 0)
// 	{
// 		param = roundf(x + vec.x);
// 		if (param < 0 || param > vars->size_line[y])
// 			break ;
// 		if (vars->map[y][param] == '1')
// 		{
// 			printf("next_x\ty = %i\tx = %i\n", y, param);
// 			return (param - x);
// 		}
// 		vec.x += 0.1;
// 	}
// 	return (0);
// }

// int	next_x_2(t_vars *vars, int x, int y, t_vector vec)
// {
// 	int	param;

// 	while (x >= 0 && param >= 0)
// 	{
// 		param = roundf(x + vec.x);
// 		if (param < 0 || param > vars->size_line[y])
// 			break ;
// 		if (vars->map[y][param] == '1')
// 		{
// 			printf("next_x\ty = %i\tx = %i\n", y, param);
// 			return (param - x);
// 		}
// 		vec.x -= 0.1;
// 	}
// 	return (0);
// }

// int	next_y(t_vars *vars, int y, int x, t_vector vec)
// {
// 	int	param;

// 	while (y >= 0 || param >= 0)
// 	{
// 		param = roundf(y + vec.y);
// 		if (param < 0 || param > vars->nb_line_map)
// 			break ;
// 		if (vars->map[param][x] == '1')
// 		{
// 			printf("next_y\ty = %i\tx = %i\n", param, x);
// 			return (y - param);
// 		}
// 		vec.y -= 0.1;
// 	}
// 	return (0);
// }

// int	next_y_2(t_vars *vars, int y, int x, t_vector vec)
// {
// 	int	param;

// 	while (y >= 0 && param >= 0)
// 	{
// 		param = roundf(y + vec.y);
// 		if (param < 0 || param > vars->nb_line_map)
// 			break ;
// 		if (vars->map[param][x] == '1')
// 		{
// 			printf("next_y\ty = %i\tx = %i\n", param, x);
// 			return (y - param);
// 		}
// 		vec.y += 0.1;
// 	}
// 	return (0);
// }

// void	print_ground_and_roof(t_vars *vars)
// {
// 	int	x;
// 	int	y;
// 	//unsigned int	color;

// 	x = -1;
// 	y = -1;
// 	while (++y <= 360)
// 	{
// 		while (++x <= 1080)
// 			mlx_pixel_put(vars->mlx, vars->win, x, y, 720); //conv char to int avec une somme a faire
// 		x = -1;
// 	}
// 	y--;
// 	while (++y <= 720)
// 	{
// 		while (++x < 1080)
// 			mlx_pixel_put(vars->mlx, vars->win, x, y, 255);
// 		x = -1;
// 	}
// }

// float	fc_pythagore(float a, float b)
// {
// 	float	res;

// 	res = a + b;
// 	res = pow(res , (0.5));
// 	return (res);
// }

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;

// 	pixel = NULL;
// 	if (y < 0 || y > 720 - 1 || x < 0 || x > 1080 - 1)
// 		return ;
// 	//printf("line_l = %i\nbits = %i\n", img->line_length, img->bits_per_pixel);
// 	pixel = (img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
// 	//printf("y = %d\n", y);
// 	*(unsigned int *)pixel = color;
// }

// int	get_rgb(int *rgb)
// {
// 	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
// }

// int	get_color(t_vars *vars, int x, int y)
// {
// 	return (*(int *)(vars->img->addr + (y * vars->img->line_length + x * (vars->img->bits_per_pixel / 8))));
// }

// void	create_img_for_print(t_vars *vars, t_vector vec, float dist, int x_pixel)
// {
// 	(void)vec;
// 	if (dist < 3)
// 	{
// 		vars->limit_wall = 720;
// 		vars->limit_ceil = 0;
// 		vars->limit_screen = 720;
// 	}
// 	else
// 	{
// 		vars->limit_wall = (1 / dist) + 1;
// 		vars->limit_ceil = 0.5 * (720 - vars->limit_wall);
// 		vars->limit_screen = 720;
// 	}
// 	int	y_pixel = 0;
// 	while (y_pixel < vars->limit_ceil - 1)
// 		my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_rgb(vars->img->roof));
// 	while (y_pixel < vars->limit_wall)
// 	{
// 		my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_color(vars, vars->ray->tex_x, vars->ray->tex_pos));
// 		vars->ray->tex_pos += vars->ray->step;
// 	}
// 	while (y_pixel < vars->limit_screen)
// 		my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_rgb(vars->img->floor));
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);

// }

// void	ft_ray_casting_rework(t_vars *vars)
// {
// 	float	fov;
// 	float	dist;
// 	t_vector	vec;
// 	int	x_pixel = 0;
// 	fov = vars->pos_p.rad - (vars->pi / 3);
// 	while (fov <= vars->pos_p.rad + (vars->pi / 3))
// 	{
// 		vec.x = cos(fov);
// 		vec.y = sin(fov);
// 		while ((int)roundf(vars->pos_p.x + vec.x) <= vars->size_line[(int)vars->pos_p.y])
// 		{
// 			if (vars->map[(int)(vars->pos_p.y + vec.y)][(int)(vars->pos_p.x + vec.x)] == '1')
// 				break ;
// 			if (vec.y > 0.1)
// 				vec.y += 0.1;
// 			if (vec.x > 0.1)
// 				vec.x += 0.1;
// 		}
// 		dist = fc_pythagore(vec.y * vec.y, vec.x * vec.x);
// 		create_img_for_print(vars, vec, dist, x_pixel);
// 		x_pixel++;
// 		fov += 0.002181662;
// 	}
// }

// void	init_cast_img(t_vars *vars)
// {
// 	vars->img = ft_malloc(sizeof(t_img) * 1, 0, 0, 0);
// 	vars->img->mlx_img = mlx_new_image(vars->mlx, vars->window_x, vars->window_y);
// 	if (!vars->img->mlx_img)
// 		end_of_prog(vars, 2);
// 	vars->img->addr = mlx_get_data_addr(vars->img->mlx_img,
// 			&(vars->img->bpp), &(vars->img->rowlen),
// 			&(vars->img->end));
// }


// void	ray_cast(t_vars *vars)
// {
// 	int		x;

// 	x = 0;
// 	init_cast_img(vars); // init img et addr
// 	while (x < vars->window_x)
// 	{
// 		set_camera(vars, vars->ray, x); // init fov, radian de depart, pos player de depart
// 		set_sidedist(vars, vars->ray); // wallah jsais pas
// 		check_hit(vars, vars->ray); // defini la dist en fonction du hit sur un wall
// 		draw_textures(vars, vars->ray, x); // define texture to print, set_textures_variables(cub, cub->ray, x); pas compris,
// 		if (vars->mini->display == 1)
// 			draw_mini_map(vars, x);
// 		x++;
// 	}
// 	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->mlx_img, 0, 0);
// 	mlx_destroy_image(cub->mlx, cub->img->mlx_img);
// }

void	define_pos_player(t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < vars->nb_line_map)
	{
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] == 'N' || vars->map[y][x] == 'S' || vars->map[y][x] == 'E' || vars->map[y][x] == 'W')
			{
				vars->pos_p.x = x;
				vars->pos_p.y = y;
				vars->pos_p.sens = vars->map[y][x];
				break;
			}
		}
		x = -1;
	}
	if (vars->pos_p.sens == 'N')
		vars->pos_p.rad = vars->pi / 2;
	if (vars->pos_p.sens == 'W')
		vars->pos_p.rad = vars->pi;
	if (vars->pos_p.sens == 'S')
		vars->pos_p.rad = (3 * vars->pi) / 2;
}
