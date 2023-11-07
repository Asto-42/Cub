/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:43:12 by jquil             #+#    #+#             */
/*   Updated: 2022/12/08 10:13:35 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mallocstr(char const *s, unsigned int start, size_t len, char *r)
{
	if (len >= ft_strlen(s) && ft_strlen(s) > start)
		r = malloc (((ft_strlen(s) - start) + 1) * sizeof(char));
	else if (start > ft_strlen(s))
		r = malloc(1 * sizeof(char));
	else
		r = malloc((len + 1) * sizeof (char));
	if (!r)
		return (NULL);
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	x;
	size_t			y;
	char			*r;

	if (!s)
		return (0);
	x = 0;
	y = 0;
	r = NULL;
	while (x < start && s[x])
		x++;
	r = ft_mallocstr(s, start, len, r);
	if (!r)
		return (NULL);
	while (y < len && s[x] && start < ft_strlen(s))
	{
		r[y] = s[x];
		y++;
		x++;
	}
	r[y] = '\0';
	return (r);
}
/*int		main(void)
{
	char	*s;
	int	st;
	int	len;
	char	*rez;

	s = "0123456789";
	st = 9;
	len = 10;
	rez = ft_substr(s, st, len);
	printf("%s\n", rez);
	return (0);


	if (ft_strlen(&s[start]) <= len && s[start] && s[start + len])
		r = malloc ((ft_strlen(&s[start]) * sizeof (char)));
	else if (start > ft_strlen(s))
		r = malloc (1 * sizeof (char));
	else if (len > ft_strlen(s))
		r = malloc ((ft_strlen(s) + 1) * sizeof(char));
	else
}*/
