/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:56 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/16 16:48:19 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*act;
	t_list	*nexts;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	act = *lst;
	while (act->next != NULL)
	{
		nexts = act->next;
		ft_lstdelone(act, del);
		act = nexts;
	}
	ft_lstdelone(act, del);
	*lst = NULL;
}
