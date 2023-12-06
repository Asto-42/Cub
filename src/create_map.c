/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:22:38 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/22 15:33:06 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	valid_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (i < 4)
		return (0);
	if (str[i] != 'b')
		return (0);
	i--;
	if (str[i] != 'u')
		return (0);
	i--;
	if (str[i] != 'c')
		return (0);
	i--;
	if (str[i] != '.')
		return (0);
	return (1);
}

unsigned int	count_line(char *av)
{
	unsigned int	i;
	int				fd;
	char			tmp[1];

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, tmp, 1) != 0)
	{
		if (tmp[0] == '\n')
			i++;
	}
	close(fd);
	return (i + 2);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size && (nmemb * size / size) != nmemb)
		return (NULL);
	if (nmemb < 1 || size < 1)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return ((unsigned char *)ptr);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map && map[i])
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		map[i] = NULL;
		free(map);
		map = NULL;
	}
}

char	**get_map(char *av)
{
	char	*line;
	char	**map;
	int		fd;
	int		i;

	i = 0;
	map = ft_calloc(count_line(av), sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (free_map(map), NULL);
	line = get_next_line(fd, 0);
	if (!line)
		return (free_map(map), close(fd), NULL);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd, 0);
		i++;
	}
	map[i] = NULL;
	return (get_next_line(fd, 1), close(fd), map);
}
