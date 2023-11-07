/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:15:07 by jquil             #+#    #+#             */
/*   Updated: 2023/10/26 15:14:49 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_contains(char *nbf)
{
	int	x;

	x = 0;
	while (nbf[x])
	{
		if (nbf[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

char	*ft_read(int fd, char *nbf, char *str2)
{
	ssize_t	r;

	r = 1;
	while (r != 0 && ft_contains(str2) == 0)
	{
		r = read(fd, nbf, BUFFER_SIZE);
		if (r == -1)
		{
			free(str2);
			return (NULL);
		}
		if (r == 0)
		{
			if (ft_strlen(str2) > 0)
				return (str2);
			free(str2);
			return (NULL);
		}
		if (r > 0)
			nbf[r] = '\0';
		str2 = ft_strjoin(str2, nbf);
	}
	nbf[0] = '\0';
	return (str2);
}

char	*ft_extract(char *str, char *str2)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	if (!str2)
		return (NULL);
	while (str2[++x] && str2[x] != '\n')
		str[x] = str2[x];
	x++;
	if (str2[x - 1] == '\n')
	{
		str[x - 1] = '\n';
		str[x] = '\0';
	}
	else
		str[x - 1] = '\0';
	while (str2[y] && str2[x - 1])
		str2[y++] = str2[x++];
	str2[y] = '\0';
	return (str);
}

char	*ft_setup(void)
{
	char	*str2;

	str2 = malloc (sizeof(char));
	if (!str2)
		return (NULL);
	str2[0] = '\0';
	return (str2);
}

char	*get_next_line(int fd)
{
	int			x;
	char		*nbf;
	char		*str;
	static char	*str2[1024];

	x = 1;
	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (NULL);
	nbf = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!nbf)
		return (NULL);
	if (!str2[fd])
		str2[fd] = ft_setup();
	nbf[0] = '\0';
	str2[fd] = ft_read(fd, nbf, str2[fd]);
	free(nbf);
	if (!str2[fd])
		return (free(str2[fd]), NULL);
	while (str2[fd][x - 1] != '\n' && str2[fd][x])
		x++;
	str = malloc ((x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_extract(str, str2[fd]);
	return (str);
}
