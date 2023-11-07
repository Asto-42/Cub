/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:31:03 by jquil             #+#    #+#             */
/*   Updated: 2023/10/26 14:29:09 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_up_down(char **map, size_t size_line, int nb_line)
{
	int	x;

	x = 0;
	while (map[0][x] != '\n' && map[nb_line][x] != '\n')
	{
		if (map[0][x] != '1' || map[nb_line][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (x < nb_line)
	{
		if (ft_strlen(map[nb_line]) != size_line + 2)
			return (0);
		if (map[x][0] != '1' || map[x][size_line] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_pars_map(char **map, int nb_line)
{
	size_t	size_line;

	size_line = ft_strlen(map[0]);
	if (size_line < 3)
		return (0);
	if (ft_check_up_down(map, size_line - 2, nb_line) != 1)
		return (0);
	return (1);
}

int	ft_check_map_char(char **map, int nb_line)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < nb_line)
	{
		while (map[y][++x] != '\n')
		{
			if (map[y][x] != '1' && map[y][x] != '0'
					&& map[y][x] != 'N' && map[y][x] != 'S'
							&& map[y][x] != 'E' && map[y][x] != 'W')
				return (0);
		}
		x = 0;
	}
	return (1);
}

int	ft_extract_map_for_parse(char *file)
{
	char	**map;
	int		fd;
	int		x;
	int		nb_line;

	x = -1;
	nb_line = ft_nb_line_empty(file) + 1;
	if (nb_line < 3)
		return (0);
	map = malloc ((nb_line + 1) * sizeof (char *));
	if (map == NULL)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (++x < nb_line)
		map[x] = get_next_line(fd);
	map[x] = NULL;
	close(fd);
	if (ft_check_map_char(map, nb_line - 1) == 0)
		return (0);
	x = ft_pars_map(map, nb_line - 2);
	free_map(map);
	return (x);
}
