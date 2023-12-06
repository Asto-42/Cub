/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_description2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:08:04 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/22 15:28:37 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_char_desc(char c, char d)
{
	if ((c == 'N' && d == 'O') || (c == 'S' && d == 'O') || (c == 'E'
			&& d == 'A') || (c == 'W' && d == 'E'))
		return (1);
	return (0);
}

int	already_exist(char **textures, char **map, int i, int k)
{
	int	j;

	j = 0;
	while (textures[j][0] != map[i][k])
		j++;
	if (textures[j][2] == '1')
		return (1);
	return (0);
}

int	get_image_name(char **map, char *str, int i, int k)
{
	int	j;

	j = 0;
	while (map[i][k] && map[i][k] != ' ' && map[i][k] != '\n')
	{
		str[j] = map[i][k];
		j++;
		k++;
	}
	while (map[i][k] && map[i][k] != '\n')
	{
		if (map[i][k] != ' ')
			return (0);
		k++;
	}
	return (1);
}

int	valid_image(char **map, int i, int k)
{
	int		tmp;
	char	*str;
	void	*mlx;
	void	*image;

	tmp = k;
	mlx = mlx_init();
	if (!mlx)
		return (0);
	while (map[i][k] && map[i][k] != ' ' && map[i][k] != '\n')
		k++;
	str = ft_calloc((k - tmp + 1), sizeof(char));
	if (!str)
		return (mlx_destroy_display(mlx), free(mlx), 0);
	k = tmp;
	if (!get_image_name(map, str, i, k))
		return (mlx_destroy_display(mlx), free(mlx), free(str), 0);
	image = mlx_xpm_file_to_image(mlx, str, &i, &i);
	if (!image)
		return (mlx_destroy_display(mlx), free(mlx), free(str), 0);
	return (mlx_destroy_image(mlx, image), mlx_destroy_display(mlx), free(mlx),
		free(str), 1);
}

int	atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
