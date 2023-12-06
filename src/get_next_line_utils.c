/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:48:51 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/22 15:28:15 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	d = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d)
		return (NULL);
	while (s1[j])
		d[i++] = s1[j++];
	j = 0;
	while (s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	free(s1);
	return (d);
}
