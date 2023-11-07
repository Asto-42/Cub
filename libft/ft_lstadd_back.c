/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:16:15 by jquil             #+#    #+#             */
/*   Updated: 2022/12/08 09:28:10 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int		y;
	t_list	*tmp;

	y = 0;
	tmp = *lst;
	if (lst == NULL || *lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
}
