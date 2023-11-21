/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/11/21 17:55:53 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	next_x(t_vars *vars, int x, int y, t_vector vec)
{
	int	param;

	while (x >= 0 && param >= 0)
	{
		param = roundf(x + vec.x);
		if (param < 0 || param > vars->size_line[y])
			break ;
		if (vars->map[y][param] == '1')
		{
			printf("next_x\ty = %i\tx = %i\n", y, param);
			return (param - x);
		}
		vec.x += 0.1;
	}
	return (0);
}

int	next_x_2(t_vars *vars, int x, int y, t_vector vec)
{
	int	param;

	while (x >= 0 && param >= 0)
	{
		param = roundf(x + vec.x);
		if (param < 0 || param > vars->size_line[y])
			break ;
		if (vars->map[y][param] == '1')
		{
			printf("next_x\ty = %i\tx = %i\n", y, param);
			return (param - x);
		}
		vec.x -= 0.1;
	}
	return (0);
}

int	next_y(t_vars *vars, int y, int x, t_vector vec)
{
	int	param;

	while (y >= 0 || param >= 0)
	{
		param = roundf(y + vec.y);
		if (param < 0 || param > vars->nb_line_map)
			break ;
		if (vars->map[param][x] == '1')
		{
			printf("next_y\ty = %i\tx = %i\n", param, x);
			return (y - param);
		}
		vec.y -= 0.1;
	}
	return (0);
}

int	next_y_2(t_vars *vars, int y, int x, t_vector vec)
{
	int	param;

	while (y >= 0 && param >= 0)
	{
		param = roundf(y + vec.y);
		if (param < 0 || param > vars->nb_line_map)
			break ;
		if (vars->map[param][x] == '1')
		{
			printf("next_y\ty = %i\tx = %i\n", param, x);
			return (y - param);
		}
		vec.y += 0.1;
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

	res = a + b;
	res = pow(res , (0.5));
	return (res);
}
void	create_img_for_print(t_vars *vars, t_vector vec, float dist)
{
	int	size_max_y;
	int	size_max_x;

	(void)vec;
	size_max_x = 720 * (1 / dist);
	size_max_y = 1080 * (1 / dist);
	int pixel_bits;
	int line_bytes;
	int endian;
	//char *buffer = malloc (size_max_x * size_max_y * 4 * sizeof (byte));
	char *buffer = mlx_get_data_addr(vars->img.north_wall, &pixel_bits, &line_bytes, &endian);
	//printf("%s\n", mlx_get_data_addr(vars->img.north_wall, &pixel_bits, &line_bytes, &endian));
	int color = 0xABCDEF;
	//printf("pixel_bits = %i\nendian = %i\n", pixel_bits, endian);
	if (pixel_bits != 32)
		color = mlx_get_color_value(vars->img.east_wall, color);
	int	y;
	int	x;
	y = -1;
	x = -1;
	while (++y < size_max_y)
	{
		while (++x < size_max_x)
		{
			if (endian == 1)		// Most significant (Alpha) byte first
			{
				buffer[(y * line_bytes) + (x * 4)] = (color >> 24); // pixel 0
				buffer[(y * line_bytes) + (x * 4)] = (color >> 16) & 0xFF; // pixel 1
				buffer[(y * line_bytes) + (x * 4)] = (color >> 8) & 0xFF; // pixel 2
				buffer[(y * line_bytes) + (x * 4)] = (color) & 0xFF; // pixel 4
			}
			//printf("size_max_y = %i\tsize_max_x = %i\nY = %i\tX = %i\n", size_max_y, size_max_x, y, x);
		}
		x = -1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, &buffer, 0, 0);
}

void	ft_ray_casting(t_vars *vars)
{
	float		fov;
	float		dist;
	float		l_y = 0;
	float		l_x = 0;
	t_vector	vec;

	print_ground_and_roof(vars);
	fov = vars->pos_p.rad - (vars->pi / 2);
	while (fov <= (vars->pos_p.rad + (vars->pi / 2)))
	{
		vec.x = cos(fov);
		vec.y = sin(fov);
		printf("pos_x = %f\tpos_y = %f\nfov = %f\nvec.y = %f\tvec.x = %f\nx^2 + y^2 = %f\n",vars->pos_p.x, vars->pos_p.y, fov,  vec.y, vec.x, vec.x*vec.x + vec.y*vec.y);
		if (vec.y > 0 && vec.y > 0.01)
			l_y = (next_y(vars, vars->pos_p.y, vars->pos_p.x, vec));
		else if (vec.y < 0 && vec.y < -0.01)
			l_y = (next_y_2(vars, vars->pos_p.y, vars->pos_p.x, vec));
		else
			l_y = 0;
		if (vec.x > 0 && vec.x > 0.01)
			l_x = (next_x(vars, vars->pos_p.x, vars->pos_p.y, vec) - 1);
		else if (vec.x < 0 && vec.x < -0.01)
			l_x = (next_x_2(vars, vars->pos_p.x, vars->pos_p.y, vec) - 1);
		else
			l_x = 0;
		dist = fc_pythagore(l_y * l_y, l_x * l_x);
		printf("l_y = %f\nl_x = %f\ndist = %f\n\n", l_y, l_x, dist);
		//create_img_for_print(vars, vec, dist);
		fov += vars->pi / 18;
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
