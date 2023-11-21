/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_description3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:09:45 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/21 20:22:58 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_len_nb(char **map, int i, int *k, int *j)
{
	if (!(map[i][*k] >= '0' && map[i][*k] <= '9'))
		return (0);
	while (map[i][*k] && map[i][*k] >= '0' && map[i][*k] <= '9')
	{
		(*k)++;
		(*j)++;
		if (*j == 4)
			return (0);
	}
	return (1);
}

int	skip_space(char **map, int i, int *k, int *nb_tour)
{
	while (map[i][*k] && map[i][*k] == ' ')
		(*k)++;
	if (((map[i][*k] != ',') && (*nb_tour <= 1)) || ((map[i][*k] == ',')
			&& (*nb_tour >= 2)))
		return (0);
	(*k)++;
	while (map[i][*k] && map[i][*k] == ' ')
		(*k)++;
	(*nb_tour)++;
	return (1);
}

void	reset_k(char **map, int i, int *k)
{
	(*k)--;
	while (map[i][*k] && map[i][*k] >= '0' && map[i][*k] <= '9')
		(*k)--;
	(*k)++;
}

int	valid_fc(char **map, int i, int k)
{
	int		j;
	int		p;
	char	*nb;
	int		nb_tour;

	nb_tour = 0;
	while (map[i][k] && map[i][k] != '\n')
	{
		j = 0;
		p = 0;
		if (!check_len_nb(map, i, &k, &j))
			return (0);
		nb = ft_calloc(j + 1, sizeof(char));
		if (!nb)
			return (0);
		reset_k(map, i, &k);
		while (j-- > 0)
			nb[p++] = map[i][k++];
		if (atoi(nb) < 0 || atoi(nb) > 255 || !skip_space(map, i, &k, &nb_tour))
			return (free(nb), 0);
		free(nb);
	}
	if (nb_tour == 3)
		return (1);
	return (0);
}

int	textures_good(char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		if (textures[i][2] != '1')
			return (0);
		i++;
	}
	return (1);
}
