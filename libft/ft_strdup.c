/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:42 by jquil             #+#    #+#             */
/*   Updated: 2022/12/02 09:00:34 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		x;
	int		y;
	char	*c;

	x = 0;
	y = 0;
	while (s[x])
		x++;
	c = malloc ((x + 1) * sizeof (char));
	if (!c)
		return (0);
	while (y <= x)
	{
		c[y] = s[y];
		y++;
	}
	return (c);
}
