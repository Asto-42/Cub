/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/12/11 13:45:11 by dberreby         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = NULL;
	if (y < 0 || y > 720 - 1 || x < 0 || x > 1080 - 1)
		return ;
	//printf("line_l = %i\nbits = %i\n", img->line_length, img->bits_per_pixel);
	pixel = (img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
	//printf("y = %d\n", y);
	*(unsigned int *)pixel = color;
}

int	get_rgb(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

// int	get_color(t_game *game, int x, int y, int i)
// {
// 	return (*(int *)(game->tex[i].addr + (y * game->tex[i].line_length + x * (game->tex[i].bits_per_pixel / 8))));
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
// 		vars->limit_wall = 1 / dist;
// 		vars->limit_ceil = 0.5 * (720 - vars->limit_wall);
// 		vars->limit_screen = 720;
// 	}
// 	int	y_pixel = 0;
// 	// printf("dist = %f\ty = %i\tlimit_ceil = %i\n",dist, y_pixel, vars->limit_ceil);
// 	// printf("1 : %i\t2 : %i\t 3 : %i\n", vars->img->roof[0], vars->img->roof[1], vars->img->roof[2]);
// 	while (y_pixel < vars->limit_ceil)
// 		my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_rgb(vars->img->roof));
// 	// while (y_pixel < vars->limit_wall)
// 	// 	my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_color(vars, raycaster->tex_x, raycaster->tex_pos, vars->texture));
// 	// 	raycaster->tex_pos += raycaster->step_tex;
// 	while (y_pixel < vars->limit_screen)
// 		my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_rgb(vars->img->floor));

// }

void	create_img_for_print(t_vars *vars, t_vector vec, float dist, int x_pixel)
{
	(void)vec;
	if (dist < 3)
	{
		vars->limit_wall = 720;
		vars->limit_ceil = 0;
		vars->limit_screen = 720;
	}
	else
	{
		vars->limit_wall = 1 / dist;
		vars->limit_ceil = 0.5 * (720 - vars->limit_wall);
		vars->limit_screen = 720;
	}
	int	y_pixel = 0;
	// printf("dist = %f\ty = %i\tlimit_ceil = %i\n",dist, y_pixel, vars->limit_ceil);
	// printf("1 : %i\t2 : %i\t 3 : %i\n", vars->img->roof[0], vars->img->roof[1], vars->img->roof[2]);
	printf("avant boucle y = %d ceil = %d\n", y_pixel, vars->limit_ceil);
	while (y_pixel < vars->limit_ceil - 1)
	{
		my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_rgb(vars->img->roof));
		printf("y = %d ceil = %d\n", y_pixel, vars->limit_ceil);
	}
	// while (y_pixel < vars->limit_wall)
	// 	my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_color(vars, raycaster->tex_x, raycaster->tex_pos, vars->texture));
	// 	raycaster->tex_pos += raycaster->step_tex;
	while (y_pixel < vars->limit_screen)
		my_mlx_pixel_put(vars->img, x_pixel, y_pixel++, get_rgb(vars->img->floor));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);

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

void	ft_ray_casting_rework(t_vars *vars)
{
	float	fov;
	float	dist;
	t_vector	vec;
	int	x_pixel = 0;
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
		//printf("before\n");
		create_img_for_print(vars, vec, dist, x_pixel);
		//printf("after\n");
		x_pixel++;
		fov += 0.002181662;
	}
}

// void	ft_ray_casting(t_vars *vars)
// {
// 	float		fov;
// 	float		dist;
// 	float		l_y = 0;
// 	float		l_x = 0;
// 	t_vector	vec;

// 	fov = vars->pos_p.rad - (vars->pi / 2);
// 	while (fov <= (vars->pos_p.rad + (vars->pi / 2)))
// 	{
// 		vec.x = cos(fov);
// 		vec.y = sin(fov);
// 		printf("pos_x = %f\tpos_y = %f\nfov = %f\nvec.y = %f\tvec.x = %f\nx^2 + y^2 = %f\n",vars->pos_p.x, vars->pos_p.y, fov,  vec.y, vec.x, vec.x*vec.x + vec.y*vec.y);
// 		// if (vec.y > 0 && vec.y > 0.01)
// 		// 	l_y = (next_y(vars, vars->pos_p.y, vars->pos_p.x, vec));
// 		// else if (vec.y < 0 && vec.y < -0.01)
// 		// 	l_y = (next_y_2(vars, vars->pos_p.y, vars->pos_p.x, vec));
// 		// else
// 		// 	l_y = 0;
// 		if (vec.x > 0 && vec.x > 0.01)
// 			l_x = (next_x(vars, vars->pos_p.x, vars->pos_p.y, vec) - 1);
// 		else if (vec.x < 0 && vec.x < -0.01)
// 			l_x = (next_x_2(vars, vars->pos_p.x, vars->pos_p.y, vec) - 1);
// 		else
// 			l_x = 0;
// 		dist = fc_pythagore(l_y * l_y, l_x * l_x);
// 		printf("l_y = %f\nl_x = %f\ndist = %f\n\n", l_y, l_x, dist);
// 		//create_img_for_print(vars, vec, dist);
// 		fov += vars->pi / 18;
// 	}
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
