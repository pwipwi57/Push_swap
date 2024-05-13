/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:58:53 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 03:28:29 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_liste **a, t_liste **b)
{
	t_liste	*temp;
	int		null;

	null = 0;
	if (*b == NULL)
		return ;
	if ((*b)->next == (*b))
		null = 1;
	temp = (*b)->next;
	remove_el(*b);
	ft_lstadd_front2(a, *b);
	*b = temp;
	if (null == 1)
		*b = NULL;
}

void	pa(t_liste **a, t_liste **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_liste **a, t_liste **b)
{
	push(b, a);
	ft_printf("pb\n");
}

void	all_pa(t_liste **a, t_liste **b)
{
	while (*b != NULL)
		pa(a, b);
}
