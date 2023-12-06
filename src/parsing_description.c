/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_description.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:28:17 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/22 15:28:37 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_textures(char **map, char **textures, int i, int *k)
{
	if (map[i][*k] && map[i][*k + 1] &&
		is_char_desc(map[i][*k], map[i][*k + 1]))
	{
		if (already_exist(textures, map, i, *k))
			return (free_map(textures), free_map(map), 0);
		*k += 2;
		while (map[i][*k] && map[i][*k] == ' ')
			(*k)++;
		if (!valid_image(map, i, *k))
			return (free_map(textures), free_map(map), 0);
		update_textures(textures, map, i);
	}
	else if (map[i][*k] == 'F' || map[i][*k] == 'C')
	{
		if (already_exist(textures, map, i, *k))
			return (free_map(textures), free_map(map), 0);
		(*k)++;
		while (map[i][*k] && map[i][*k] == ' ')
			(*k)++;
		if (!valid_fc(map, i, *k))
			return (free_map(textures), free_map(map), 0);
		update_textures(textures, map, i);
	}
	return (1);
}

int	char_is_desc_or_fc(char **map, int i, int k)
{
	if ((map[i][k] && map[i][k + 1] && is_char_desc(map[i][k], map[i][k
				+ 1])) || map[i][k] == 'F' || map[i][k] == 'C')
		return (1);
	return (0);
}

int	valid_description(char **map)
{
	char	**textures;
	int		i;
	int		k;

	i = -1;
	k = 0;
	textures = init_textures();
	if (!textures)
		return (0);
	while (map[++i])
	{
		while (map[i][k] && map[i][k] == ' ')
			k++;
		if (char_is_desc_or_fc(map, i, k))
		{
			if (!check_textures(map, textures, i, &k))
				return (0);
		}
		else if (map[i][k] != '1' && map[i][k] != '\n')
			return (free_map(textures), free_map(map), 0);
		k = 0;
	}
	if (textures_good(textures))
		return (free_map(textures), 1);
	return (free_map(textures), free_map(map), 0);
}

// int	valid_image(char **map, int i, int k)
// {
// 	int		j;
// 	int		tmp;
// 	char	*str;
// 	void	*mlx;
// 	void	*image;

// 	j = 0;
// 	tmp = k;
// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (0);
// 	while (map[i][k] && map[i][k] != ' ' && map[i][k] != '\n')
// 		k++;
// 	str = ft_calloc((k - tmp + 1), sizeof(char));
// 	if (!str)
// 		return (mlx_destroy_display(mlx), free(mlx), 0);
// 	k = tmp;
// 	while (map[i][k] && map[i][k] != ' ' && map[i][k] != '\n')
// 	{
// 		str[j] = map[i][k];
// 		j++;
// 		k++;
// 	}
// 	image = mlx_xpm_file_to_image(mlx, str, &j, &j);
// 	if (!image)
// 		return (mlx_destroy_display(mlx), free(mlx), free(str), 0);
// 	return (mlx_destroy_image(mlx, image), mlx_destroy_display(mlx), free(mlx),
// 		free(str), 1);
// }

//if (ft_atoi(nb) < 0 || ft_atoi(nb) > 255 || !skip_space(map, i, &k, &nb_tour))
// int	valid_fc(char **map, int i, int k)
// {
// 	int		j;
// 	int		p;
// 	char	*nb;
// 	int		nb_tour;

// 	j = 0;
// 	p = 0;
// 	nb_tour = 0;
// 	while (map[i][k] && map[i][k] != '\n')
// 	{
// 		if (!(map[i][k] >= '0' && map[i][k] <= '9'))
// 			return (printf("erreur 1\n"), 0);
// 		while (map[i][k] && map[i][k] >= '0' && map[i][k] <= '9')
// 		{
// 			k++;
// 			j++;
// 			if (j == 4)
// 				return (0);
// 		}
// 		nb = ft_calloc(j + 1, sizeof(char));
// 		if (!nb)
// 			return (printf("erreur 2\n"), 0);
// 		k--;
// 		while (map[i][k] && map[i][k] >= '0' && map[i][k] <= '9')
// 			k--;
// 		k++;
// 		while (j > 0)
// 		{
// 			nb[p] = map[i][k];
// 			k++;
// 			p++;
// 			j--;
// 		}
// 		if (ft_atoi(nb) < 0 || ft_atoi(nb) > 255)
// 			return (printf("erreur 3\n"), free(nb), 0);
// 		free(nb);
// 		while (map[i][k] && map[i][k] == ' ')
// 			k++;
// 		if (((map[i][k] != ',') && (nb_tour <= 1)) || ((map[i][k] == ',')
// 				&& (nb_tour >= 2)))
// 			return (printf("erreur 4\n"), 0);
// 		k++;
// 		while (map[i][k] && map[i][k] == ' ')
// 			k++;
// 		p = 0;
// 		nb_tour++;
// 	}
// 	if (nb_tour == 3)
// 		return (1);
// 	return (0);
// }

// int	valid_description(char **map)
// {
// 	char	**textures;
// 	int		i;
// 	int		k;

// 	i = 0;
// 	k = 0;
// 	textures = NULL;
// 	textures = init_textures();
// 	if (!textures)
// 		return (0);
// 	while (map[i])
// 	{
// 		while (map[i][k] && map[i][k] == ' ')
// 			k++;
// 		if (map[i][k] && map[i][k + 1] && is_char_desc(map[i][k], map[i][k
// 				+ 1]))
// 		{
// 			if (already_exist(textures, map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			k += 2;
// 			while (map[i][k] && map[i][k] == ' ')
// 				k++;
// 			if (!valid_image(map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			update_textures(textures, map, i);
// 		}
// 		else if (map[i][k] == 'F' || map[i][k] == 'C')
// 		{
// 			if (already_exist(textures, map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			k++;
// 			while (map[i][k] && map[i][k] == ' ')
// 				k++;
// 			if (!valid_fc(map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			update_textures(textures, map, i);
// 		}
// 		else if (map[i][k] != '1' && map[i][k] != '\n')
// 			return (free_map(textures), free_map(map), 0);
// 		k = 0;
// 		i++;
// 	}
// 	if (textures_good(textures))
// 		return (free_map(textures), 1);
// 	return (free_map(textures), free_map(map), 0);
// }

// int	valid_description(char **map)
// {
// 	char	**textures;
// 	int		i;
// 	int		k;

// 	i = 0;
// 	k = 0;
// 	textures = NULL;
// 	if (!init_textures(&textures))
// 		return (0);
// 	while (map[i])
// 	{
// 		while (map[i][k] && map[i][k] == ' ')
// 			k++;
// 		if (map[i][k] && map[i][k + 1] && is_char_desc(map[i][k], map[i][k
// 				+ 1]))
// 		{
// 			if (already_exist(textures, map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			k += 2;
// 			while (map[i][k] && map[i][k] == ' ')
// 				k++;
// 			if (!valid_image(map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			update_textures(textures, map, i, k);
// 		}
// 		else if (map[i][k] == 'F' || map[i][k] == 'C')
// 		{
// 			if (already_exist(textures, map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			k++;
// 			while (map[i][k] && map[i][k] == ' ')
// 				k++;
// 			if (!valid_FC(map, i, k))
// 				return (free_map(textures), free_map(map), 0);
// 			update_textures(textures, map, i, k);
// 		}
// 		else if (map[i][k] != '1' && map[i][k] != '\n')
// 			return (free_map(textures), free_map(map), 0);
// 		k = 0;
// 		i++;
// 	}
// 	if (textures_good(textures))
// 		return (free_map(textures), free_map(map), 1);
// 	return (free_map(textures), 0);
// }
