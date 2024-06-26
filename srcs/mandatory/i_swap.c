/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:39:27 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 03:27:40 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_liste **a)
{
	int	temp;

	if (*a == NULL || (*a)->next == (*a))
		return ;
	temp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = temp;
	return ;
}

void	sa(t_liste **a)
{
	swap(a);
	ft_printf("sa\n");
	return ;
}

void	sb(t_liste **b)
{
	swap(b);
	ft_printf("sb\n");
	return ;
}

void	ss(t_liste **a, t_liste **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	return ;
}
