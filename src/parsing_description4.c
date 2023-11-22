/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_description4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:10:40 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/21 20:23:03 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

char	**calloc_textures(void)
{
	int		i;
	char	**textures;

	i = 0;
	textures = ft_calloc(7, sizeof(char *));
	if (!textures)
		return (0);
	while (i < 7)
	{
		textures[i] = ft_calloc(4, sizeof(char));
		if (!textures[i])
			return (free_map(textures), NULL);
		i++;
	}
	return (textures);
}

char	**init_textures(void)
{
	char	**textures;

	textures = calloc_textures();
	if (!textures)
		return (NULL);
	textures[0][0] = 'N';
	textures[1][0] = 'S';
	textures[2][0] = 'E';
	textures[3][0] = 'W';
	textures[4][0] = 'F';
	textures[5][0] = 'C';
	textures[0][1] = 'O';
	textures[1][1] = 'O';
	textures[2][1] = 'A';
	textures[3][1] = 'E';
	textures[4][1] = '0';
	textures[5][1] = '0';
	textures[0][2] = '0';
	textures[1][2] = '0';
	textures[2][2] = '0';
	textures[3][2] = '0';
	textures[4][2] = '0';
	textures[5][2] = '0';
	free(textures[6]);
	return (textures[6] = NULL, textures);
}

void	update_textures(char **textures, char **map, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (map[i][k] && map[i][k + 1] && !is_char_desc(map[i][k], map[i][k + 1])
		&& map[i][k] != 'F' && map[i][k] != 'C')
		k++;
	while (textures[j] && textures[j][0] != map[i][k])
		j++;
	if (textures[j])
		textures[j][2] = '1';
}
