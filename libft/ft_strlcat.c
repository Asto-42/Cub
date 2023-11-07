/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:55 by jquil             #+#    #+#             */
/*   Updated: 2022/12/12 10:10:11 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	n;

	n = 0;
	x = ft_strlen(src);
	y = 0;
	if (size == 0 && (!dst || !src))
		return (0);
	while (dst[y] && y < size)
		y++;
	if (size == 0)
		return (ft_strlen(src));
	while (src[n] && n + y < size - 1)
	{
		dst[y + n] = src[n];
		n++;
	}
	if (y != size)
		dst[y + n] = 0;
	return (y + x);
}

/*int	main(void)
{
	const char *src;
	size_t	size;
	size_t	x;
	size_t	y;
	char dst[30]; memset(dst, 'B', 4);

	dst[0] = 'B';
	src = "AAAAAAAAA";
	size = 6;
	x = ft_strlcat(dst, src, size);
	printf("src + dst : %li\n", x);
	printf("src = %li\n", ft_strlen(src));
	printf("dst = %li\n", ft_strlen(dst));
	printf("should be :%li\n", ft_strlen(src) + 4);
	return (0);
}*/
