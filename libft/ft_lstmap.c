/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:19:11 by jquil             #+#    #+#             */
/*   Updated: 2022/12/02 11:28:13 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new || !lst || !(*f) || !del)
		return (NULL);
	lst2 = new;
	while (lst)
	{
		lst2->content = (*f)(lst -> content);
		if (lst->next)
		{
			lst2->next = malloc(sizeof(t_list));
			if (lst2->next == NULL)
			{
				ft_lstclear(&new, (*del));
				return (NULL);
			}
		}
		lst = lst -> next;
		if (lst)
			lst2 = lst2->next;
	}
	lst2->next = NULL;
	return (new);
}
