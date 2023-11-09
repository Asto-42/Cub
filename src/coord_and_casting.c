/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/11/09 16:57:15 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	next_x(t_vars *vars, int x, int y, t_vector vec)
{
	int	param;

	while (x >= 0 && param >= 0)
	{
		param = roundf(x + vec.x);
		// printf("param = %i\n", param);
		// printf("map = %c\n", vars->map[y][param]);
		if (param < 0 || param > vars->size_line[y])
			break ;
		if (vars->map[y][param] == '1')
			return (param - x + 1);
		vec.x += 1;
	}
	return (0);
}

int	next_y(t_vars *vars, int y, int x, t_vector vec)
{
	int	param;

	while (y >= 0 && param >= 0)
	{
		param = roundf(y + vec.y);
		if (param < 0 || param > vars->nb_line_map)
			break ;
		if (vars->map[param][x] == '1')
			return (y - param);
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

	// printf("a = %f\tb = %f\n", a, b);
	res = a + b;
	// printf("res = %f\n", res);
	res = pow(res , (0.5));
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
		vec.x = cos(fov);
		vec.y = sin(fov);
		if (vec.y < -0.01 || vec.y > 0.01)
			l_y = (vars->pos_p.y - next_y(vars, vars->pos_p.y, vars->pos_p.x, vec));
		else
			l_y = 0;
		if (vec.x < -0.01 || vec.x > 0.01)
			l_x = (vars->pos_p.x + next_x(vars, vars->pos_p.x, vars->pos_p.y, vec));
		else
			l_x = 0;
		dist = fc_pythagore(l_y, l_x);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.east_wall, 0, 180);
		// print differentes image en fonction du fov
		// print l'image a 1 / dist + cste
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
