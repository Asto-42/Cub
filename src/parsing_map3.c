/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:13:36 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:17 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	longest_line(char **file, int i)
{
	int	longest;

	longest = len(file[i]);
	while (file[i] && contain_wall(file[i]))
	{
		if (longest < len(file[i]))
			longest = len(file[i]);
		i++;
	}
	return (longest);
}

char	**calloc_map(char **map, int i, int line, char **file)
{
	int	k;
	int	longest;

	k = 0;
	map = ft_calloc(line - i + 1, sizeof(char *));
	if (!map)
		return (free_map(map), NULL);
	longest = longest_line(file, i);
	while (file[i] && contain_wall(file[i]))
	{
		map[k] = ft_calloc(longest + 1, sizeof(char));
		if (!map[k])
			return (free_map(map), NULL);
		k++;
		i++;
	}
	return (map[k] = NULL, map);
}

char	**extract_map(char **file, char **map, int i)
{
	int	line;
	int	longest;

	line = i;
	longest = longest_line(file, i);
	while (file[line] && contain_wall(file[line]))
		line++;
	map = calloc_map(map, i, line, file);
	if (!map)
		return (free_map(map), NULL);
	line = 0;
	while (file[i] && contain_wall(file[i]))
	{
		if (!extract_line(map[line], file[i], longest))
			return (free_map(map), NULL);
		line++;
		i++;
	}
	map[line] = NULL;
	return (map);
}

int	valid_char(char **file, int i, int k)
{
	int	player;

	player = 0;
	while (file[i])
	{
		while (file[i][k] && file[i][k] != '\n')
		{
			if (file[i][k] == 'N' || file[i][k] == 'S' || file[i][k] == 'W'
				|| file[i][k] == 'E')
			{
				if (player == 1)
					return (0);
				else
					player = 1;
				k++;
			}
			else if (!(file[i][k] == '1' || file[i][k] == '0'
					|| file[i][k] == ' '))
				return (0);
			k++;
		}
		k = 0;
		i++;
	}
	return (player);
}

int	fl_line_walled(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
