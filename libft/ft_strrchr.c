/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:28:16 by jquil             #+#    #+#             */
/*   Updated: 2022/12/05 14:36:43 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	*s1;

	s1 = (char *)s;
	x = ft_strlen(s);
	while (c > 256)
		c = c - 256;
	while (s1[x] != c && x > 0)
		x--;
	if (s1[x] == c)
		return (&s1[x]);
	else
		return (NULL);
}
