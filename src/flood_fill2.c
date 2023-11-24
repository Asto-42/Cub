/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:57:12 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/24 20:57:53 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	size_min(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (i < 3)
		return (0);
	return (1);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = ft_calloc(i + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		copy[i] = ft_calloc(longest_line(map, 0) + 1, sizeof(char));
		if (!copy[i])
			return (free_map(copy), NULL);
	}
	copy[i] = NULL;
	i = -1;
	while (map[++i])
		ft_strlcpy(copy[i], map[i], len(map[i]));
	return (copy);
}

int	find_player(char **map, int *i, int *k)
{
	while (map[*i])
	{
		while (map[*i][*k])
		{
			if (map[*i][*k] == 'N' || map[*i][*k] == 'S' || map[*i][*k] == 'W'
				|| map[*i][*k] == 'E')
				return (1);
			(*k)++;
		}
		(*k) = 0;
		(*i)++;
	}
	return (0);
}

int	contain_two(char **map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		while (map[i][k])
		{
			if (map[i][k] == '2')
				return (1);
			k++;
		}
		k = 0;
		i++;
	}
	return (0);
}

int	find_two(char **map, int *i, int *k)
{
	while (map[*i])
	{
		while (map[*i][*k])
		{
			if (map[*i][*k] == '2')
				return (1);
			(*k)++;
		}
		(*k) = 0;
		(*i)++;
	}
	return (0);
}
