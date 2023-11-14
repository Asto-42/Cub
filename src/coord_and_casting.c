/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/11/14 14:16:07 by jquil            ###   ########.fr       */
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
void	create_img_for_print(t_vars *vars, t_vector vec, float dist)
{
	float	size_max_y;
	float	size_max_x;

	(void)vec;
	(void)vars;
	size_max_x = 720 * (1 / dist);
	size_max_y = 1080 * (1 / dist);
	//define image en fonction de vec & fov
	//

	int *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;

	// int color = 0xABCDEF;

	// for(int y = 0; y < 360; ++y)
	// for(int x = 0; x < 640; ++x)
	// {
	// 	buffer[(y * line_bytes) + x] = color;
	// }


	//get_data_addr for print pixel by pixel in img ?
	//char *mlx_get_data_addr( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
	//print differentes image en fonction du fov
	//print l'image a 1 / dist + cste
	//byte = (color >> 8) & 0xFF;
}

void	ft_ray_casting(t_vars *vars)
{
	float		fov;
	float		dist;
	float		l_y;
	float		l_x;
	int			scale;
	t_vector	vec;

	scale = 0;
	print_ground_and_roof(vars);
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
		// create l'img, dessiner dedans puis la print -> create_img_for_print
		// manque la data de la coordonnee a laquelle le rayon hit le wall, faisable ?
		printf("dist = %f\nl_y = %f\nl_x = %f\nvec.y = %f\tvec.x = %f\n", dist, l_y, l_x, vec.y, vec.x);
		//mlx_put_image_to_window(vars->mlx, vars->win, create_img_for_print(vars, vec, dist), scale, 180);
		fov += 0.1;
		scale += 64;
		//scale usless, surement besoin d'use size_max_x et size_max_y dans le create img - print direct dans create_img ?
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
