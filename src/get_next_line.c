/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:48:32 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/21 20:22:12 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

char	*get_line(char *full_line)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!full_line)
		return (NULL);
	while (full_line[i] && full_line[i] != '\n')
		i++;
	if (full_line[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = malloc((sizeof(char) * i) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (full_line[i] && full_line[i] != '\n')
		line[j++] = full_line[i++];
	if (full_line[i] == '\n')
		line[j++] = full_line[i++];
	line[j] = '\0';
	return (line);
}

char	*reserve(char *full_line)
{
	char	*reservoir;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strchr(full_line, '\n'))
	{
		free(full_line);
		return (NULL);
	}
	while (full_line[i] && full_line[i] != '\n')
		i++;
	reservoir = malloc(sizeof(char) * (ft_strlen(full_line) - i + 1));
	if (!reservoir)
		return (NULL);
	i++;
	while (full_line[i] != '\0')
		reservoir[j++] = full_line[i++];
	reservoir[j] = full_line[i];
	free(full_line);
	return (reservoir);
}

char	*get_full_line(int fd, char *full_line)
{
	int		readnb;
	char	*buffer;

	readnb = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readnb > 0 && !(ft_strchr(full_line, '\n')))
	{
		readnb = read(fd, buffer, BUFFER_SIZE);
		if (readnb == -1)
		{
			free(buffer);
			free(full_line);
			return (NULL);
		}
		buffer[readnb] = '\0';
		full_line = ft_strjoin(full_line, buffer);
	}
	free(buffer);
	return (full_line);
}

char	*get_next_line(int fd, int flag)
{
	static char	*full_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(full_line);
		return (NULL);
	}
	if (flag == 1)
	{
		free(full_line);
		return (NULL);
	}
	if (!full_line)
	{
		full_line = malloc(1);
		full_line[0] = '\0';
	}
	full_line = get_full_line(fd, full_line);
	if (full_line == NULL)
		return (NULL);
	line = get_line(full_line);
	full_line = reserve(full_line);
	return (line);
}
