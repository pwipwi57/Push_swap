/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:59:54 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/09 05:02:57 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_liste **a)
{
	if (*a == NULL)
		return ;
	(*a) = (*a)->next;
	return ;
}

void	ra(t_liste **a)
{
	if (*a == NULL)
		return ;
	rotate(a);
	ft_printf("ra\n");
	return ;
}

void	rb(t_liste **b)
{
	if (*b == NULL)
		return ;
	rotate(b);
	ft_printf("rb\n");
	return ;
}

void	rr(t_liste **a, t_liste **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	return ;
}
