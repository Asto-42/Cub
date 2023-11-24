/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:23:31 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/24 17:42:18 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	line_walled(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] != '1')
		return (0);
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ')
		i--;
	if (str[i] != '1')
		return (0);
	return (1);
}

int	space_walled(char **map, int i, int k)
{
	if (map[i - 1][k] == ' ')
		return (0);
	if (map[i + 1][k] == ' ')
		return (0);
	if (map[i][k - 1] == ' ')
		return (0);
	if (map[i][k + 1] == ' ')
		return (0);
	return (1);
}

int	is_walled(char **map)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (map[i + 1])
	{
		if (!line_walled(map[i]))
			return (0);
		while (map[i][k])
		{
			while (map[i][k] && map[i][k] != '0')
				k++;
			if (map[i][k] == '0' && !space_walled(map, i, k))
				return (0);
			if (map[i][k])
				k++;
		}
		k = 0;
		i++;
	}
	if (!fl_line_walled(map[0]) || !fl_line_walled(map[i]))
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
	if (!size_min(map))
		return (free_map(map), free_map(file), 0);
	if (!is_walled(map))
		return (free_map(map), free_map(file), 0);
	if (!flood_fill(map))
		return (free_map(map), free_map(file), 0);
	return (free_map(map), 1);
}

int	valid_parsing(char *av)
{
	char	**file;
	int		res;

	res = 1;
	file = get_map(av);
	if (!file)
		return (0);
	if (!valid_name(av))
		return (free_map(file), 0);
	if (!valid_description(file) || !valid_map(file))
		res = 0;
	if (res == 1)
		free_map(file);
	return (res);
}

// int	calloc_map(char **map, int i, int line, char **file)
// {
// 	int k;
// 	int longest;

// 	k = i;
// 	map = ft_calloc(line - i, + 1, sizeof(char *));
// 	if (!map)
// 		return (free_map(map), 0);
// 	longest = ft_strlen(file[i]);
// 	while (file[i] && contain_wall(file[i]))
// 	{
// 		if (longest < ft_strlen(file[i]))
// 			longest = ft_strlen(file[i]);
// 		i++;
// 	}
// 	i = k;
// 	k = 0;
// 	while (file[i] && contain_wall(file[i]))
// 	{
// 		map[k] = ft_calloc(longest + 1, sizeof(char));
// 		if (!map[k])
// 			return (free_map(map), 0);
// 		k++;
// 		i++;
// 	}
// 	return (map[k] = NULL, 1);
// }

// int	calloc_map(char **map, int i, int line, char **file)
// {
// 	int k;
// 	int longest;

// 	k = 0;
// 	map = ft_calloc(line - i + 1, sizeof(char *));
// 	if (!map)
// 		return (free_map(map), 0);
// 	longest = longest_line(file, i);
// 	while (file[i] && contain_wall(file[i]))
// 	{
// 		map[k] = ft_calloc(longest + 1, sizeof(char));
// 		if (!map[k])
// 			return (free_map(map), 0);
// 		k++;
// 		i++;
// 	}
// 	return (map[k] = NULL, 1);
// }

// int	extract_map(char **file, char **map, int i)
// {
// 	int	line;
// 	int longest;

// 	line = i;
// 	longest = longest_line(file, i);
// 	while (file[line] && contain_wall(file[line]))
// 		line++;
// 	if (!calloc_map(map, i, line, file))
// 		if (!map)
// 			return (0);
// 	line = 0;
// 	printf("dans extract map\n");
// 	printf("file i = %s\n", file[i]);
// 	while (file[i] && contain_wall(file[i]))
// 	{
// 		if (!extract_line(map[line], file[i], longest))
// 			return (free_map(map), 0);
// 		line++;
// 		i++;
// 	}
// 	map[line] = NULL;
// 	return (1);
// }

// int	extract_map(char **file, char **map, int i)
// {
// 	int	line;
// 	int longest;

// 	line = i;
// 	longest = longest_line(file, i);
// 	while (file[line] && contain_wall(file[line]))
// 		line++;
// 	map = calloc_map(map, i, line, file);
// 	if (!map)
// 		return (free_map(map), 0);
// 	line = 0;
// 	printf("dans extract map\n");
// 	printf("file i = %s\n", file[i]);
// 	while (file[i] && contain_wall(file[i]))
// 	{
// 		if (!extract_line(map[line], file[i], longest))
// 			return (free_map(map), 0);
// 		line++;
// 		i++;
// 	}
// 	map[line] = NULL;
// 	return (1);
// }

// int	valid_char(char **file, int i, int k)
// {
// 	int	player;

// 	player = 0;
// 	while (file[i])
// 	{
// 		while (file[i][k] && file[i][k] != '\n')
// 		{
// 			if (file[i][k] == 'N' || file[i][k] == 'S' || file[i][k] == 'W'
// 				|| file[i][k] == 'E')
// 			{
// 				if (player == 1)
// 					return (0);
// 				else
// 					player = 1;
// 				k++;
// 			}
// 			else if (file[i][k] == '1' || file[i][k] == '0'
// 					|| file[i][k] == ' ')
// 				k++;
// 			else
// 				return (0);
// 		}
// 		k = 0;
// 		i++;
// 	}
// 	return (player);
// }

// int	valid_map(char **file)
// {
// 	int		i;
// 	int		k;
// 	char	**map;

// 	i = 0;
// 	k = 0;
// 	map = NULL;
// 	if (!find_start_map(file, &i, &k))
// 		return (0);
// 	k = 0;
// 	if (!valid_char(file, i, k))
// 		return (0);
// 	map = extract_map(file, map, i);
// 	if (!map)
// 		return (0);
// 	if (!is_walled(map))
// 		return (0);
// 	return (free_map(map), 1);
// }
