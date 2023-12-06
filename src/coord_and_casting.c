/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/12/06 14:11:37 by jquil            ###   ########.fr       */
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
	while (++y <= 360)
	{
		while (++x <= 1080)
			mlx_pixel_put(vars->mlx, vars->win, x, y, 720); //conv char to int avec une somme a faire
		x = -1;
	}
	y--;
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
	(void)vars;
	(void)vec;
	(void)dist;
}

// void	draw_colone(t_raycaster *raycaster, t_game *game, int x)
// {
// 	int	tmp;

// 	tmp = 0;
// 	init_spread(game, raycaster);
// 	while (tmp < raycaster->draw_start)
// 		my_mlx_pixel_put(game->imgptr, x, tmp++, game->rgb_ceiling);
// 	while (tmp < raycaster->draw_end)
// 	{
// 		my_mlx_pixel_put(game->imgptr, x, tmp, get_color(game, raycaster->tex_x, raycaster->tex_pos, game->texture));
// 		raycaster->tex_pos += raycaster->step_tex;
// 		tmp++;
// 	}
// 	while (tmp < W_HEIGHT)
// 		my_mlx_pixel_put(game->imgptr, x, tmp++, game->rgb_floor);
// }

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;

// 	if (y < 0 || y > W_HEIGHT - 1 || x < 0 || x > W_WIDTH - 1)
// 		return ;
// 	pixel = (img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
// 	*(unsigned int *)pixel = color;
// }

void	ft_ray_casting_rework(t_vars *vars)
{
	float	fov;
	float	dist;
	t_vector	vec;

	fov = vars->pos_p.rad - (vars->pi / 4);
	while (fov <= vars->pos_p.rad + (vars->pi / 4))
	{
		vec.x = cos(fov);
		vec.y = sin(fov);
		while ((int)roundf(vars->pos_p.x + vec.x) <= vars->size_line[(int)vars->pos_p.y])
		{
			if (vars->map[(int)(vars->pos_p.y + vec.y)][(int)(vars->pos_p.x + vec.x)] == '1')
				break ;
			if (vec.y > 0.1)
				vec.y += 0.1;
			if (vec.x > 0.1)
				vec.x += 0.1;
		}
		dist = fc_pythagore(vec.y * vec.y, vec.x * vec.x);
		create_img_for_print(vars, vec, dist);
		fov += vars->pi / 18;
	}
}

void	ft_ray_casting(t_vars *vars)
{
	float		fov;
	float		dist;
	float		l_y = 0;
	float		l_x = 0;
	t_vector	vec;

	fov = vars->pos_p.rad - (vars->pi / 2);
	while (fov <= (vars->pos_p.rad + (vars->pi / 2)))
	{
		vec.x = cos(fov);
		vec.y = sin(fov);
		printf("pos_x = %f\tpos_y = %f\nfov = %f\nvec.y = %f\tvec.x = %f\nx^2 + y^2 = %f\n",vars->pos_p.x, vars->pos_p.y, fov,  vec.y, vec.x, vec.x*vec.x + vec.y*vec.y);
		// if (vec.y > 0 && vec.y > 0.01)
		// 	l_y = (next_y(vars, vars->pos_p.y, vars->pos_p.x, vec));
		// else if (vec.y < 0 && vec.y < -0.01)
		// 	l_y = (next_y_2(vars, vars->pos_p.y, vars->pos_p.x, vec));
		// else
		// 	l_y = 0;
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
