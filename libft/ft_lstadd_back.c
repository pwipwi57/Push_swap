/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:01:14 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/16 16:48:02 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*act;

	if (lst == NULL || *lst == NULL)
	{
		*lst = new;
		return ;
	}
	act = ft_lstlast(*lst);
	act->next = new;
}
