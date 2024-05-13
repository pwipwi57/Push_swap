/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:13:56 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/09 03:04:54 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_lstnew2(int nbr)
{
	t_liste	*new;

	new = malloc(sizeof(t_liste));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->prev = new;
	new->next = new;
	new->rank = 100000;
	return (new);
}

void	ft_lstadd_front2(t_liste **lst, t_liste *new)
{
	if (new == NULL && lst && *lst)
		ft_lstclear2(lst);
	else if (*lst == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
		new->next = *lst;
	}
	*lst = new;
}

void	ft_lstdelone2(t_liste *lst)
{
	if (lst == NULL)
		return ;
	del(lst);
	free(lst);
}

void	ft_lstclear2(t_liste **lst)
{
	t_liste	*act;
	t_liste	*nexts;

	if (lst == NULL || *lst == NULL)
		return ;
	act = *lst;
	while (act->next != *lst)
	{
		nexts = act->next;
		ft_lstdelone2(act);
		act = nexts;
	}
	ft_lstdelone2(act);
	*lst = NULL;
}

void	del(t_liste *lst)
{
	lst->prev = NULL;
	lst->next = NULL;
	lst->nbr = 0;
	lst->rank = 0;
}
