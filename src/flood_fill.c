/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:07:31 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/24 21:08:05 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	replace_two(char **map, int i, int k)
{
	if (map[i - 1][k] == ' ' || map[i + 1][k] == ' ' || map[i][k - 1] == ' '
		|| map[i][k + 1] == ' ')
		return (0);
	if (map[i - 1][k] == '0')
		map[i - 1][k] = '2';
	if (map[i + 1][k] == '0')
		map[i + 1][k] = '2';
	if (map[i][k - 1] == '0')
		map[i][k - 1] = '2';
	if (map[i][k + 1] == '0')
		map[i][k + 1] = '2';
	return (1);
}

int	flood_fill(char **map)
{
	char	**copy;
	int		i;
	int		k;

	i = 0;
	k = 0;
	copy = copy_map(map);
	if (!copy)
		return (0);
	if (!find_player(copy, &i, &k) || i == 0)
		return (free_map(copy), 0);
	copy[i][k] = '2';
	while (contain_two(copy))
	{
		i = 0;
		k = 0;
		find_two(copy, &i, &k);
		copy[i][k] = '3';
		if (!replace_two(map, i, k))
			return (free_map(copy), 0);
	}
	return (free_map(copy), 1);
}
