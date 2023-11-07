/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:08:46 by jquil             #+#    #+#             */
/*   Updated: 2023/10/23 14:09:17 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	*ft_size_line(char **map, int nb_line)
{
	int	x;
	int	*size_line;

	x = -1;
	size_line = malloc (nb_line * sizeof(int));
	while (++x < nb_line)
		size_line[x] = ft_strlen(map[x]);
	return (size_line);
}

int	ft_nb_line(char **map)
{
	int		nb_line;

	nb_line = 0;
	while (map[nb_line])
		nb_line++;
	return (nb_line);
}
