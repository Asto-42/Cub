/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:26 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/23 16:36:29 by dberreby         ###   ########.fr       */
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
	game->img->floor = ft_calloc(3, sizeof(int));
	if (!game->img->floor)
		return (0);
	game->img->roof = ft_calloc(3, sizeof(int));
	if (!game->img->roof)
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

int	load_image(t_vars *game, char *str, char dir, int i)
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

int	extract_fc(t_vars *game, char **file, int i, int k)
{
	char	c;
	char	*nb;
	int		len;
	int		p;
	int		color;

	c = file[i][k];
	color = 0;
	k++;
	while (file[i][k] && file[i][k] == ' ')
		k++;
	while (file[i][k] && file[i][k] != '\n')
	{
		len = 0;
		p = 0;
		check_len_nb(file, i, &k, &len);
		nb = ft_calloc(len + 1, sizeof(char));
		if (!nb)
			return (0);
		reset_k(file, i, &k);
		while (len-- > 0)
			nb[p++] = file[i][k++];
		if (c == 'F')
			game->img->floor[color++] = atoi(nb);
		else if (c == 'C')
			game->img->roof[color++] = atoi(nb);
		skip_space(file, i, &k, &color);
		free(nb);
	}
	return (1);
}

int	extract_textures(t_vars *game, char **file)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (file[i])
	{
		while (file[i] && !contain_texture(file[i]))
			i++;
		if (!file[i])
			break ;
		while (file[i][k] && file[i][k] == ' ')
			k++;
		if (is_char_desc(file[i][k], file[i][k + 1]) && !extract_image(game,
				file, i, k))
			return (0);
		else if ((file[i][k] == 'F' || file[i][k] == 'C') && !extract_fc(game,
					file, i, k))
			return (0);
		k = 0;
		i++;
	}
}

int	init_mlx(t_vars *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 1080, 720,
			"The adventure of Pjay vol.2");
	if (!game->mlx)
		return (0);
	return (1);
}

int	valid_map(char **file)
{
	int		i;
	int		k;
	char	**map;

	i = 0;
	k = 0;
	map = NULL;
	if (!find_start_map(file, &i, &k))
		return (free_map(file), 0);
	k = 0;
	if (!valid_char(file, i, k))
		return (free_map(file), 0);
	map = extract_map(file, map, i);
	if (!map)
		return (free_map(map), free_map(file), 0);
	if (!is_walled(map))
		return (free_map(map), free_map(file), 0);
	return (free_map(map), 1);
}

int	init_map(t_vars *game, char **file)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!find_start_map(file, &i, &k))
		return (0);
	game->map = extract_map(file, game->map, i);
	if (!game->map)
		return (free_map(map), free_map(file), 0);
	return (1);
}

void	print_map(t_vars *game)
{
	int i;

	i = 0;
	while (game->map[i])
	{
		printf("%s\n", gme->map[i]);
		i++;
	}
}

int	init_game(t_vars *game, char *filename)
{
	char **file;

	if (!set_var_null(game))
		return (0);
	file = get_map(filename);
	if (!file)
		return (0);
	if (!init_mlx(game))
		return (0);
	if (!extract_textures(game, file))
		return (0);
	if (!init_map(game, file))
		return (0);
	print_map(game);
	return (1);
}