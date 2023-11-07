/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:16:38 by jquil             #+#    #+#             */
/*   Updated: 2022/11/10 14:58:14 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new_nb;

	if (n < 0)
	{
		new_nb = -n;
		ft_putchar('-', fd);
	}
	else
		new_nb = n;
	if (new_nb >= 10)
	{
		ft_putnbr_fd(new_nb / 10, fd);
		ft_putnbr_fd(new_nb % 10, fd);
	}
	if (new_nb < 10)
		ft_putchar(new_nb + 48, fd);
}
