/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:14:58 by jquil             #+#    #+#             */
/*   Updated: 2022/12/12 10:11:47 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*x;

	if (nmemb >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	x = malloc(nmemb * size);
	if (!x)
		return (NULL);
	ft_memset(x, 0, size * nmemb);
	return (x);
}
