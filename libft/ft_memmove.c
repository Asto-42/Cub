/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:14:11 by jquil             #+#    #+#             */
/*   Updated: 2022/12/08 10:32:52 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove2(char *s1, char *s2, size_t x, size_t n)
{
	while (x < n)
	{
		s1[x] = s2[x];
		x++;
	}
	return (s1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	x;
	char	*s1;
	char	*s2;

	if (!dest && !src)
		return (0);
	x = 0;
	s1 = (char *)dest;
	s2 = (char *)src;
	if (s1 > s2)
	{
		while (n > 0)
		{
			s1[n - 1] = s2[n - 1];
			n--;
		}
	}
	else
		ft_memmove2(s1, s2, x, n);
	return (dest);
}
