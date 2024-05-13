/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_insert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:30:26 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 03:29:43 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert(t_liste **a, t_liste **b, int pivot, int min)
{
	if (!(*b))
		return ;
	while (end_insert(b, pivot))
		insert_pivot(a, b);
	while (end_insert(b, min))
		insert_pivot(a, b);
}

int	end_insert(t_liste **b, int min)
{
	if (!(*b))
		return (0);
	if ((*b)->nbr >= min || (*b)->next->nbr >= min
		|| (*b)->prev->nbr >= min)
		return (1);
	return (0);
}

void	insert_pivot(t_liste **a, t_liste **b)
{
	t_liste	*el;
	int		dir;
	int		nbr;

	el = *b;
	if (test_rank_el(el) && el->nbr < (*a)->nbr
		&& ((el->nbr > (*a)->prev->nbr) || (*a)->prev->nbr > (*a)->nbr))
	{
		pa(a, b);
		return ;
	}
	choose(*a, *b, &dir, &nbr);
	move(a, b, dir, nbr);
	pa(a, b);
	return ;
}

void	move(t_liste **a, t_liste **b, int dir, int nbr)
{
	while (dir == 1 && (*b)->nbr != nbr && nbr > (*a)->nbr)
		rr(a, b);
	while (dir == 1 && (*b)->nbr != nbr)
		rb(b);
	while (dir == 0 && (*b)->nbr != nbr
		&& nbr < (*a)->prev->nbr && (*a)->prev->nbr < (*a)->nbr)
		rrr(a, b);
	while (dir == 0 && (*b)->nbr != nbr)
		rrb(b);
	while (nbr > (*a)->nbr)
		ra(a);
	while (nbr < (*a)->prev->nbr && (*a)->prev->nbr < (*a)->nbr)
		rra(a);
}

int	test_rank_el(t_liste *b)
{
	if (b->rank >= b->prev->rank && b->rank >= b->next->rank)
		return (1);
	return (0);
}
