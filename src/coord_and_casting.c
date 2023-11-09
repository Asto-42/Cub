/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/11/09 14:26:37 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	next_x(t_vars *vars, int x, int y, t_vector vec)
{
	int	param;

	while (x >= 0 && param >= 0)
	{
		param = roundf(x - vec.x);
		if (param < 0 || param > vars->size_line[y])
			break ;
		if (vars->map[y][param] == 1)
			return (x);
		vec.x += 1;
	}
	return (0);
}

int	next_y(t_vars *vars, int y, int x, t_vector vec)
{
	int	param;

	while (y >= 0 && param >= 0)
	{
		param = roundf(y - vec.y);
		if (param > 0 || param > vars->nb_line_map)
			break ;
		// printf("param = %i\n", param);
		// printf("map = %c\n", vars->map[param][x]);
		if (vars->map[param][x] == 1)
			return (y);
		vec.y += 1;
	}
	return (0);
}

void	print_ground_and_roof(t_vars *vars)
{
	int	x;
	int	y;
	//unsigned int	color;

	x = -1;
	y = -1;
	// color = mlx_get_color_value(vars->mlx, 2);
	// color += mlx_get_color_value(vars->mlx, 10);
	// color += mlx_get_color_value(vars->mlx, 300);
	while (++y <= 360)
	{
		while (++x <= 1080)
			mlx_pixel_put(vars->mlx, vars->win, x, y, 720); //conv char to int avec une somme a faire
		x = -1;
	}
	while (++y <= 720)
	{
		while (++x < 1080)
			mlx_pixel_put(vars->mlx, vars->win, x, y, 255);
		x = -1;
	}
}

float	fc_pythagore(float a, float b)
{
	float	res;

	printf("a = %f\tb = %f\n", a, b);
	res = a + b;
	res = pow(res , (1/2));
	return (res);
}

void	ft_ray_casting(t_vars *vars)
{
	float		h;
	float		fov;
	float		dist;
	float		l_y;
	float		l_x;
	t_vector	vec;

	print_ground_and_roof(vars);
	h = 1;
	fov = vars->pos_p.rad - (vars->pi / 2);
	while (fov <= (vars->pos_p.rad + (vars->pi / 2)))
	{
		while (h >= 0)
		{
			vec.x = cos(vars->pos_p.rad);
			vec.y = sin(vars->pos_p.rad);
			printf("vec.x = %f\tvec.y = %f\n", vec.x, vec.y);
			l_y = vec.y * next_y(vars, vars->pos_p.y, vars->pos_p.x, vec);
			printf("l.y = %f\n", l_y);
			l_x = vec.x * next_x(vars, vars->pos_p.x, vars->pos_p.y, vec); //next_x et next_y a rework, non fonctionnel
			printf("l_x = %f\n", l_x);
			dist = fc_pythagore(l_y, l_x);
			dist = fc_pythagore((dist * dist), (h * h));
			printf("dist = %f\n", dist);
			usleep(1000000);
			//printf("dist = %f\n", dist);
			// mlx_put_pixel_to_window -> 1 / dist
			//mlx_put_image_to_window(vars->mlx, vars->win, *img_ptr, x, y);
			dist = fc_pythagore(l_y, l_x);
			dist = fc_pythagore((dist * dist), ((h + 1) * (h + 1)));
			// mlx_put_pixel_to_windox -> 1 / dist
			h -= 0.1;
		}
		h = 1;
		fov += 0.1;
	}
}

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
