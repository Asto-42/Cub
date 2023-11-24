/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:12:25 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:22 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	find_start_map(char **file, int *i, int *k)
{
	while (file[*i])
	{
		while (file[*i][*k] && file[*i][*k] == ' ')
			(*k)++;
		if (file[*i][*k] == '1')
			break ;
		*k = 0;
		(*i)++;
	}
	if (!file[*i])
		return (0);
	return (1);
}

int	contain_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	find_first_and_last_one(int *first, int *last, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '1')
		i++;
	if (!str[i])
		return (0);
	*first = i;
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] && str[i] != '1')
		i--;
	*last = i;
	if (*last == *first)
		return (0);
	return (1);
}

int	extract_line(char *map_line, char *file_line, int longest)
{
	int	i;

	i = 0;
	if (!longest)
		return (0);
	while (file_line[i] && file_line[i] != '\n')
	{
		map_line[i] = file_line[i];
		i++;
	}
	while (i < longest)
	{
		map_line[i] = ' ';
		i++;
	}
	return (1);
}

int	len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
