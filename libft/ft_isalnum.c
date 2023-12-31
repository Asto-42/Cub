/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:27:00 by jquil             #+#    #+#             */
/*   Updated: 2022/12/08 10:32:18 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((48 <= c && 57 >= c)
		|| (65 <= c && 90 >= c)
		|| (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
