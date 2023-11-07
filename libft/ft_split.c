/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:48:56 by jquil             #+#    #+#             */
/*   Updated: 2022/12/12 10:09:28 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s[x])
	{
		if (s[x] != c)
		{
			y++;
			while (s[x] && s[x] != c)
				x++;
		}
		else
			x++;
	}
	return (y);
}

char	**ft_split2(char const *s, char c, char **rez)
{
	int	a;
	int	b;
	int	x;

	x = 0;
	a = 0;
	b = 0;
	while (s[x] == c && s[x])
		x++;
	while (s[x])
	{
		if (s[x] == c)
		{
			rez[a][b] = '\0';
			a++;
			b = 0;
			while (s[x] == c && s[x])
				x++;
		}
		if (s[x] != c && s[x])
			rez[a][b++] = s[x++];
	}
	rez[a][b] = '\0';
	return (rez);
}

int	ft_mallocstring(char const *s, char c, int a)
{
	int	x;
	int	xmin;
	int	r;
	int	rank;

	x = 0;
	xmin = 0;
	rank = 0;
	a = a + 1;
	while (s[x] && s[x] == c)
		x++;
	while (rank < a)
	{
		while (s[x] && s[x] == c)
			x++;
		rank++;
		xmin = x;
		while (s[x] && s[x] != c)
			x++;
	}
	r = x - xmin;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	int		y;
	char	**rez;

	if (!s)
		return (0);
	y = ft_countword(s, c);
	rez = malloc ((y + 1) * sizeof(char *));
	if (!rez)
		return (0);
	a = 0;
	while (a <= y)
	{
		rez[a] = malloc (((ft_mallocstring(s, c, a)) + 1) * sizeof(char));
		if (!rez[a])
			return (0);
		a++;
	}
	rez = ft_split2(s, c, rez);
	free(rez[y]);
	rez[y] = NULL;
	return (rez);
}

/*int	main(void)
{
	char const	*s;
	char		c;
	char		**rez;

	c = '|';
	s = "split  ||this|for|me|||||!|";
	rez = ft_split(s, c);
	if (rez[1])
		printf("%s\n", rez[1]);
	if (rez[2])
		printf("%s\n", rez[2]);
	if (rez[3])
		printf("%s\n", rez[3]);
	if (rez[4])
		printf("%s\n", rez[4]);
	if (rez[5])
		printf("%s\n", rez[5]);
	if (rez[6])
		printf("%s\n", rez[6]);
	if (rez[7])
		printf("%s\n", rez[7]);
	if (rez[8])
		printf("%s\n", rez[8]);
	return (0);
}
*/
