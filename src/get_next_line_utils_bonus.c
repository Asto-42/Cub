/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:17:54 by jquil             #+#    #+#             */
/*   Updated: 2023/11/16 11:32:00 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_verif(char const *s1, char const *s2, char *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (0);
	if (s1)
		x = ft_strlen(s1);
	if (s2)
		y = ft_strlen(s2);
	s = malloc(((x + y) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*s;

	s = NULL;
	s = ft_verif(s1, s2, s);
	if (!s)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x])
	{
		s[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		s[x] = s2[y];
		x++;
		y++;
	}
	s[x] = '\0';
	free(s1);
	return (s);
}
