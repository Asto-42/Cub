/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2023/12/12 18:03:07 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*pixel;

	pixel = NULL;
	if (y < 0 || y > (int)vars->win_x - 1 || x < 0 || x > 1080 - 1)
		return ;
	pixel = (vars->image->addr + (y * vars->image->line_length + x * (vars->image->bpp / 8)));
	*(unsigned int *)pixel = color;
}

int	get_rgb(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	get_color(t_vars *vars, int x, int y)
{
	// (*(int *)(addr + (y * rowlen + x * (bpp / 8))));
	printf("texture = %d\n", vars->data->texture);
	if (vars->data->texture == 0)
	{
		int x3 = (y * vars->north_wall->line_length + x * (vars->north_wall->bpp / 8));
		return (*(int *)((vars->north_wall->addr) + x3));
	}
	else if (vars->data->texture == 1)
	{
		int x4 = (y * vars->south_wall->line_length + x * (vars->south_wall->bpp / 8));
		return (*(int *)((vars->south_wall->addr) + x4));
	}
	else if (vars->data->texture == 2)
	{
		int x5 =  (y * vars->west_wall->line_length + x * (vars->west_wall->bpp / 8));
		return (*(int *)((vars->west_wall->addr) + x5));
	}
	else if (vars->data->texture == 3)
	{
		int x2 = (y * vars->east_wall->line_length + x * (vars->east_wall->bpp / 8));
		return (*(int *)((vars->east_wall->addr) + x2));
	}
	/*if (vars->data->texture == 0)
		return (*(int *)(vars->north_wall->addr + (y * vars->north->line_length + x * (vars->north->bpp / 8))));
	else if (vars->data->texture == 1)
		return (*(int *)(vars->south_wall->addr + (y * vars->south_wall->line_length + x * (vars->south_wall->bpp / 8))));
	else if (vars->data->texture == 2)
		return (*(int *)(vars->west_wall->addr + (y * vars->image->line_length + x * (vars->image->bpp / 8))));
	else if (vars->data->texture == 3)
		return (*(int *)(vars->east_wall->addr + (y * vars->image->line_length + x * (vars->image->bpp / 8))));*/
	return (0);
}

void	create_img_for_print(t_vars *vars, int x_pixel)
{
	int	y_pixel= 0;

	if (vars->ray->side == 0 && vars->ray->diray_x < 0)
		vars->data->texture = 3;
	else if (vars->ray->side == 0 && vars->ray->diray_x > 0)
		vars->data->texture = 2;
	else if (vars->ray->side == 1 && vars->ray->diray_y < 0)
		vars->data->texture = 1;
	else if (vars->ray->side == 1 && vars->ray->diray_y > 0)
		vars->data->texture = 0;
	printf("texture ww= %d\n", vars->data->texture);

	vars->ray->wall_x = 0;
	vars->ray->tex_pos = 0;
	vars->ray->draw_start = -vars->ray->line_height / 2 + vars->win_y / 2;
	if (vars->ray->draw_start < 0 || vars->ray->draw_start > (int)vars->win_y)
		vars->ray->draw_start = 0;
	vars->ray->draw_end = vars->ray->line_height / 2 + vars->win_y / 2;
	if (vars->ray->draw_end >= (int)vars->win_y)
		vars->ray->draw_end = vars->win_y - 1;
	if (vars->ray->side == 0)
		vars->ray->wall_x = vars->data->p_pos_y + vars->ray->ray_length * vars->ray->diray_y;
	else
		vars->ray->wall_x = vars->data->p_pos_x + vars->ray->ray_length * vars->ray->diray_x;
	vars->ray->wall_x -= floor(vars->ray->wall_x);
	if (vars->data->texture == 0)
	{
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0) || (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->north_wall->tex_width - vars->ray->tex_x - 1;
		else
			vars->ray->tex_x = (int)(vars->ray->wall_x * (double)vars->north_wall->tex_width);
		vars->ray->step = 1 * vars->north_wall->tex_height / vars->ray->line_height;
	}
	else if (vars->data->texture == 1)
	{
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0) || (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->south_wall->tex_width - vars->ray->tex_x - 1;
		else
			vars->ray->tex_x = (int)(vars->ray->wall_x * (double)vars->south_wall->tex_width);
		vars->ray->step = 1 * vars->south_wall->tex_height / vars->ray->line_height;
	}
	else if (vars->data->texture == 2)
	{
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0) || (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->west_wall->tex_width - vars->ray->tex_x - 1;
		else
			vars->ray->tex_x = (int)(vars->ray->wall_x * (double)vars->west_wall->tex_width);
		vars->ray->step = 1 * vars->west_wall->tex_height / vars->ray->line_height;
	}
	else if (vars->data->texture == 3)
	{
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0) || (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->east_wall->tex_width - vars->ray->tex_x - 1;
		else
			vars->ray->tex_x = (int)(vars->ray->wall_x * (double)vars->east_wall->tex_width);
		vars->ray->step = 1 * vars->east_wall->tex_height / vars->ray->line_height;
	}
	vars->ray->tex_pos = (vars->ray->draw_start - vars->win_y
			/ 2 + vars->ray->line_height / 2) * vars->ray->step;

	y_pixel= vars->ray->draw_start;
	while (y_pixel>= 0)
	{
		my_mlx_pixel_put(vars, x_pixel, y_pixel, vars->rgb_ceiling);
		y_pixel--;
	}
	y_pixel= vars->ray->draw_start;
	while (y_pixel <= vars->ray->draw_end)
	{
		my_mlx_pixel_put(vars, x_pixel, y_pixel, get_color(vars, vars->ray->tex_x, vars->ray->tex_pos));
		vars->ray->tex_pos += vars->ray->step;
		y_pixel++;
	}
	while (y_pixel< (int)vars->win_y)
	{
		my_mlx_pixel_put(vars, x_pixel, y_pixel, vars->rgb_floor);
		y_pixel++;
	}

}

void	set_camera(t_vars *vars, t_ray *ray, int x)
{
	ray->camera = 2 * x / vars->win_x - 1;
	ray->diray_x = vars->data->p_ori_x + vars->data->plane_x * ray->camera;
	ray->diray_y = vars->data->p_ori_y + vars->data->plane_y * ray->camera;
	ray->map_x = (int)vars->pos_p.x;
	ray->map_y = (int)vars->pos_p.y;
	if (ray->diray_x != 0)
		ray->delta_dist_x = fabs(1 / ray->diray_x);
	else
		ray->delta_dist_x = INT_MAX;
	if (ray->diray_y != 0)
		ray->delta_dist_y = fabs(1 / ray->diray_y);
	else
		ray->delta_dist_y = INT_MAX;
}

void	set_sidedist(t_vars *vars)
{
	vars->data->p_pos_y = vars->pos_p.y;
	vars->data->p_pos_x = vars->pos_p.x;
	if (vars->ray->diray_x < 0)
	{
		vars->ray->step_x = -1;
		vars->ray->side_dist_x = (vars->data->p_pos_x - vars->ray->map_x) * vars->ray->delta_dist_x;
	}
	else
	{
		vars->ray->step_x = 1;
		vars->ray->side_dist_x = (vars->ray->map_x + 1 - vars->data->p_pos_x) * vars->ray->delta_dist_x;
	}
	if (vars->ray->diray_y < 0)
	{
		vars->ray->step_y = -1;
		vars->ray->side_dist_y = (vars->data->p_pos_y - vars->ray->map_y) * vars->ray->delta_dist_y;
	}
	else
	{
		vars->ray->step_y = 1;
		vars->ray->side_dist_y = (vars->ray->map_y + 1 - vars->data->p_pos_y) * vars->ray->delta_dist_y;
	}
}

void	check_hit(t_vars *vars, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (vars->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->ray_length = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->ray_length = ray->side_dist_y - ray->delta_dist_y;
	if (ray->ray_length < 0.005)
		ray->ray_length = 0.005;
	ray->line_height = vars->win_y / (ray->ray_length);
}

void	ft_ray_casting_rework(t_vars *vars)
{
	int	x_pixel = 0;

	vars->image = malloc(sizeof(t_img));
		if (!vars->image)
			return ;
	vars->image->img = mlx_new_image(vars->mlx, 1080, vars->win_x);
	vars->image->addr = mlx_get_data_addr(vars->image->img, &vars->image->bpp, &vars->image->line_length, &vars->image->endian);
	while (x_pixel < (int)vars->win_x)
	{
		set_camera(vars, vars->ray, x_pixel);
		set_sidedist(vars);
		check_hit(vars, vars->ray);
		create_img_for_print(vars, x_pixel);
		x_pixel++;
	}
}

void	init_data_game(t_vars *vars, char sens)
{
	if (sens == 'N')
	{
		vars->pos_p.rad = vars->pi / 2;
		vars->data->p_ori_x = 0;
		vars->data->p_ori_y = 1;
		vars->data->plane_x = -0.66;
		vars->data->plane_y = 0;
	}
	else if (sens == 'S')
	{
		vars->pos_p.rad = (3 * vars->pi) / 2;
		vars->data->p_ori_x = 0;
		vars->data->p_ori_y = 1;
		vars->data->plane_x = -0.66;
		vars->data->plane_y = 0;
	}
	else if (sens == 'W')
	{
		vars->pos_p.rad = vars->pi;
		vars->data->p_ori_x = -1;
		vars->data->p_ori_y = 0;
		vars->data->plane_x = 0;
		vars->data->plane_y = -0.66;
	}
	else if (sens == 'E')
	{
		vars->pos_p.rad = 0;
		vars->data->p_ori_x = 1;
		vars->data->p_ori_y = 0;
		vars->data->plane_x = 0;
		vars->data->plane_y = 0.66;
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
	init_data_game(vars, vars->pos_p.sens);
}
