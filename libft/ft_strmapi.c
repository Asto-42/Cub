/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:49 by jquil             #+#    #+#             */
/*   Updated: 2022/11/14 18:31:35 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*s2;
	unsigned int		x;
	unsigned int		y;

	x = 0;
	y = 0;
	if (!s || !f)
		return (0);
	while (s[x])
		x++;
	s2 = malloc ((x + 1) * sizeof (char));
	if (!s2)
		return (0);
	while (y < x)
	{
		s2[y] = f(y, s[y]);
		y++;
	}
	s2[y] = '\0';
	return (s2);
}
