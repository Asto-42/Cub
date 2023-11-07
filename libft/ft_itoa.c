/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:01:11 by jquil             #+#    #+#             */
/*   Updated: 2022/12/08 10:32:34 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_isneg(char *str, int r)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	while (x >= 1 && str[x - 1])
	{
		str[x] = str[x - 1];
		x--;
	}
	str[0] = '-';
	if (r == 1)
		str[10] = '8';
	return (str);
}

int	ft_pow(int n)
{
	int	x;
	int	p;

	p = 0;
	x = 1;
	while (x <= (n / 10))
		x = x * 10;
	while (x > 0)
	{
		p++;
		x = x / 10;
	}
	return (p);
}

char	*ft_itoa2(char *str, int r, int s, int n)
{
	int	c;
	int	x;
	int	a;
	int	p;

	x = 1;
	a = 0;
	c = 0;
	p = ft_pow(n);
	while (a < p - 1)
	{
		x = x * 10;
		a++;
	}
	while (c < p)
	{
		str[c] = (n / x) + 48;
		c++;
		n = n % x;
		x = x / 10;
	}
	str[c] = '\0';
	if (s == 1)
		str = ft_isneg(str, r);
	return (str);
}

char	*ft_itoa(int n)
{
	int		s;
	int		p;
	int		r;
	char	*str;

	s = 0;
	p = 0;
	r = 0;
	if (n == INT_MIN)
	{
		n = n + 1;
		r = 1;
	}
	if (n < 0)
	{
		n = -n;
		s = 1;
	}
	p = ft_pow(n);
	str = malloc ((s + p + 1) * sizeof(char));
	if (!str)
		return (0);
	str = ft_itoa2(str, r, s, n);
	str[p + s] = '\0';
	return (str);
}
/*
int	main(void)
{
	int		x;
	char	*s;
	char	*s2;

	x = -10;
	s = ft_itoa(x);
	printf("%s", s);
	return (0);
}
*/
