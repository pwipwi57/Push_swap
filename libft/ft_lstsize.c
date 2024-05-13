/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:10:52 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/16 16:49:03 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*act;

	if (lst == NULL)
		return (0);
	i = 1;
	act = lst;
	while (act->next != NULL)
	{
		act = act->next;
		i++;
	}
	return (i);
}
