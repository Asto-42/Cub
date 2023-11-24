/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:56:03 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/24 20:56:36 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	init_extract(char **file, int i, int *k, int *color)
{
	*color = 0;
	(*k)++;
	while (file[i][*k] && file[i][*k] == ' ')
		(*k)++;
}

int	extract_fc(t_vars *game, char **file, int i, int k)
{
	char	c;
	char	*nb;
	int		len;
	int		p;
	int		color;

	c = file[i][k];
	init_extract(file, i, &k, &color);
	while (file[i][k] && file[i][k] != '\n')
	{
		len = 0;
		p = 0;
		check_len_nb(file, i, &k, &len);
		nb = ft_calloc(len + 1, sizeof(char));
		if (!nb)
			return (0);
		reset_k(file, i, &k);
		while (len-- > 0)
			nb[p++] = file[i][k++];
		put_color_in_struct(game, c, color, nb);
		skip_space(file, i, &k, &color);
		free(nb);
	}
	return (1);
}

int	extract_textures(t_vars *game, char **file)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (file[i])
	{
		while (file[i] && !contain_texture(file[i]))
			i++;
		if (!file[i])
			break ;
		while (file[i][k] && file[i][k] == ' ')
			k++;
		if (is_char_desc(file[i][k], file[i][k + 1]) && !extract_image(game,
				file, i, k))
			return (0);
		else if ((file[i][k] == 'F' || file[i][k] == 'C') && !extract_fc(game,
					file, i, k))
			return (0);
		k = 0;
		i++;
	}
	return (1);
}

int	init_mlx(t_vars *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 1080, 720,
			"The adventure of Pjay vol.2");
	if (!game->mlx)
		return (0);
	return (1);
}

int	init_map(t_vars *game, char **file)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!find_start_map(file, &i, &k))
		return (0);
	game->map = extract_map(file, game->map, i);
	if (!game->map)
		return (0);
	return (1);
}
