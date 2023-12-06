/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:55:00 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/24 20:55:48 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	set_var_null(t_vars *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->size_line = NULL;
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (0);
	game->img->north_wall = NULL;
	game->img->south_wall = NULL;
	game->img->east_wall = NULL;
	game->img->west_wall = NULL;
	game->img->addr = NULL;
	game->img->floor = ft_calloc(4, sizeof(int));
	if (!game->img->floor)
		return (free(game->img), 0);
	game->img->roof = ft_calloc(4, sizeof(int));
	if (!game->img->roof)
		return (free(game->img->floor), free(game->img), 0);
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
		game->img->north_wall = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->img->north_wall)
			return (0);
	}
	else if (dir == 'S')
	{
		game->img->south_wall = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->img->south_wall)
			return (0);
	}
	if (dir == 'E')
	{
		game->img->east_wall = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->img->east_wall)
			return (0);
	}
	if (dir == 'W')
	{
		game->img->west_wall = mlx_xpm_file_to_image(game->mlx, str, &i, &i);
		if (!game->img->west_wall)
			return (0);
	}
	return (1);
}

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
		game->img->floor[color] = atoi(nb);
	else if (c == 'C')
		game->img->roof[color] = atoi(nb);
}