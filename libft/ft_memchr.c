/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:37:33 by jquil             #+#    #+#             */
/*   Updated: 2022/12/08 10:08:14 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	x = 0;
	while (c > 256)
		c = c - 256;
	while (x < n)
	{
		if (s1[x] == (unsigned char)c)
			return (&s1[x]);
		x++;
	}
	return (NULL);
}
