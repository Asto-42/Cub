/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:42:06 by jquil             #+#    #+#             */
/*   Updated: 2022/12/05 11:32:49 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	y;
	size_t	i;
	char	*b;
	char	*l;

	b = (char *)big;
	l = (char *)little;
	y = 0;
	if (l[0] == '\0' || !l)
		return (b);
	if (len == 0)
		return (NULL);
	while (b[y] && y < len)
	{
		i = 0;
		while (l[i] == b[y + i] && l[i] && b[y + i] && y + i < len)
			i++;
		if (!l[i])
			return (b + y);
		y++;
	}
	return (0);
}
