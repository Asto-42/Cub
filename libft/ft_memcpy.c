/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:08:24 by jquil             #+#    #+#             */
/*   Updated: 2022/12/02 08:47:39 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	x;
	char	*s1;
	char	*s2;

	if (!dest && !src)
		return (0);
	s1 = (char *)dest;
	s2 = (char *)src;
	x = 0;
	while (x < n)
	{
			s1[x] = s2[x];
			x++;
	}
	return (dest);
}
