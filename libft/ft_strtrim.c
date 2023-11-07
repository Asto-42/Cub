/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:48:34 by jquil             #+#    #+#             */
/*   Updated: 2022/12/02 09:57:03 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_init(char *s1, char *set)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s1[x])
	{
		while (set[y])
		{
			if (s1[x] != set[y])
				y++;
			else
			{
				x++;
				y = 0;
			}
		}
		return (x);
	}
	return (x);
}

int	ft_end(char *s1, char *set)
{
	int	x;
	int	y;

	x = (ft_strlen(s1)) - 1;
	y = 0;
	while (x >= 0)
	{
		while (set[y])
		{
			if (s1[x] != set[y])
				y++;
			else
			{
				x--;
				y = 0;
			}
		}
		return (x);
	}
	return (x);
}

char	*ft_s(char *s1, char *set)
{
	size_t		st;
	size_t		end;
	int			x;
	char		*r;

	x = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (s1);
	st = ft_init(s1, set);
	end = ft_end(s1, set);
	if (st == ft_strlen(s1))
	{
		r = malloc(1 * sizeof(char));
		r[0] = '\0';
		return (r);
	}
	r = malloc (((end - st) + 2) * sizeof (char));
	if (!r)
		return (0);
	while (st <= end)
		r[x++] = s1[st++];
	r[x] = '\0';
	return (r);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s1b;
	char	*setb;
	char	*s;

	if (!s1 || !set)
		return (0);
	s1b = (char *)s1;
	setb = (char *)set;
	s = ft_s(s1b, setb);
	return (s);
}

/*
#include <stdio.h>
int	main(void)
{
	const char *s1;
	const	char *set;
	char	*s;
	char	*s2;
	int		size;
	s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	set = " \n\t";
	s2 = "Hello \t  Please\n Trim me !";
	s = ft_strtrim(s1, set);
	printf("%s", s);
	return (0);
}
*/
