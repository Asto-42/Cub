/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:55:00 by dberreby          #+#    #+#             */
/*   Updated: 2023/12/12 14:40:14 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

// int	set_var_null(t_vars *game)
// {
// 	game->mlx = NULL;
// 	game->win = NULL;
// 	game->map = NULL;
// 	game->size_line = NULL;
// 	game->pi = M_PI;
// 	game->img = malloc(sizeof(t_img));
// 	if (!game->img)
// 		return (0);
// 	game->img->img = NULL;
// 	game->img->addr = NULL;
// 	game->img->bits_per_pixel = 0;
// 	game->img->line_length = 0;
// 	game->img->endian = 0;
// 	game->img->north_wall = NULL;
// 	game->img->south_wall = NULL;
// 	game->img->east_wall = NULL;
// 	game->img->west_wall = NULL;
// 	game->img->floor = ft_calloc(4, sizeof(int));
//	if (!game->img->floor)
// 		return (free(game->img), 0);
// 	game->img->roof = ft_calloc(4, sizeof(int));
// 	if (!game->img->roof)
// 		return (free(game->img->floor), free(game->img), 0);
// 	return (1);
// }

int	set_var_null(t_vars *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->size_line = NULL;
	game->pi = M_PI;
	game->floor = NULL;
	game->roof = NULL;
	game->north_wall = NULL;
	game->south_wall = NULL;
	game->east_wall = NULL;
	game->west_wall = NULL;
	game->north_wall = malloc(sizeof(t_img ));
	if (!game->north_wall)
		return (0);
	game->south_wall = malloc(sizeof(t_img ));
	if (!game->south_wall)
		return (0);
	game->east_wall = malloc(sizeof(t_img ));
	if (!game->east_wall)
		return (0);
	game->west_wall = malloc(sizeof(t_img ));
	if (!game->west_wall)
		return (0);
	game->floor = ft_calloc(4, sizeof(int));
	if (!game->floor)
		return (0);
	game->roof = ft_calloc(4, sizeof(int));
	if (!game->roof)
		return (0);
	return (1);
}

int	contain_texture(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E'
		|| str[i] == 'F' || str[i] == 'C')
		return (1);
	return (0);
}

int	load_images(t_vars *game, char *str, char dir, int i)
{
	if (dir == 'N')
	{
		game->north_wall->img = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->north_wall->img)
			return (0);
	}
	else if (dir == 'S')
	{
		game->south_wall->img = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->south_wall->img)
			return (0);
	}
	if (dir == 'E')
	{
		game->east_wall->img = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->east_wall->img)
			return (0);
	}
	if (dir == 'W')
	{
		game->west_wall->img = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->west_wall->img)
			return (0);
	}
	return (1);
}

// void	init_tex(t_vars *game, char dir)
// {
// 	if (dir == 'N')
// 		game->north_wall->addr = mlx_get_data_addr(game->north_wall->img,
// 				&game->north_wall->bpp, &game->north_wall->line_length,
// 				&game->north_wall->endian);
// 	else if (dir == 'S')
// 		game->south_wall->addr = mlx_get_data_addr(game->south_wall->img,
// 				&game->south_wall->bpp, &game->south_wall->line_length,
// 				&game->south_wall->endian);
// 	else if (dir == 'E')
// 		game->east_wall->addr = mlx_get_data_addr(game->east_wall->img,
// 				&game->east_wall->bpp, &game->east_wall->line_length,
// 				&game->east_wall->endian);
// 	else if (dir == 'W')
// 		game->west_wall->addr = mlx_get_data_addr(game->west_wall->img,
// 				&game->west_wall->bpp, &game->west_wall->line_length,
// 				&game->west_wall->endian);
// }

int	extract_image(t_vars *game, char **file, int i, int k)
{
	int		tmp;
	char	dir;
	char	*str;

	dir = file[i][k];
	k += 2;
	while (file[i][k] && file[i][k] == ' ')
		k++;
	tmp = k;
	while (file[i][k] && file[i][k] != ' ' && file[i][k] != '\n')
		k++;
	str = ft_calloc((k - tmp + 1), sizeof(char));
	if (!str)
		return (0);
	k = tmp;
	if (!get_image_name(file, str, i, k))
		return (free(str), 0);
	if (!load_images(game, str, dir, i))
		return (free(str), 0);
	return (free(str), 1);
}

void	put_color_in_struct(t_vars *game, char c, int color, char *nb)
{
	if (c == 'F')
		game->floor[color] = atoi(nb);
	else if (c == 'C')
		game->roof[color] = atoi(nb);
}
