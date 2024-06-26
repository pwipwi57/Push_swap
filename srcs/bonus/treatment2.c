/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:29:33 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	treat3el(t_liste **a)
{
	t_liste	*el;
	int		nbr1;
	int		nbr2;
	int		nbr3;

	el = *a;
	nbr1 = el->nbr;
	nbr2 = el->next->nbr;
	nbr3 = el->next->next->nbr;
	if (nbr1 < nbr2 && nbr2 < nbr3)
		return ;
	else if (nbr1 > nbr2 && nbr2 > nbr3)
		(sa(a), rra(a));
	else if (nbr1 < nbr2 && nbr2 > nbr3 && nbr1 < nbr3)
		(sa(a), ra(a));
	else if (nbr1 < nbr2 && nbr2 > nbr3 && nbr1 > nbr3)
		rra(a);
	else if (nbr1 > nbr2 && nbr2 < nbr3 && nbr1 < nbr3)
		sa(a);
	else if (nbr1 > nbr2 && nbr2 < nbr3 && nbr1 > nbr3)
		ra(a);
}

void	treat3el_bis(t_liste **a, t_liste **b)
{
	t_liste	*el;
	int		nbr1;
	int		nbr2;
	int		nbr3;

	el = *a;
	nbr1 = el->nbr;
	nbr2 = el->next->nbr;
	nbr3 = el->next->next->nbr;
	if (nbr1 < nbr2 && nbr2 < nbr3)
		sb(b);
	else if (nbr1 > nbr2 && nbr2 > nbr3)
		(ss(a, b), rra(a));
	else if (nbr1 < nbr2 && nbr2 > nbr3 && nbr1 < nbr3)
		(ss(a, b), ra(a));
	else if (nbr1 < nbr2 && nbr2 > nbr3 && nbr1 > nbr3)
		rrr(a, b);
	else if (nbr1 > nbr2 && nbr2 < nbr3 && nbr1 < nbr3)
		ss(a, b);
	else if (nbr1 > nbr2 && nbr2 < nbr3 && nbr1 > nbr3)
		rr(a, b);
}

void	treat4el(t_liste **a, t_liste **b)
{
	int		min;
	t_liste	*el;

	el = *a;
	min = min_nbr(a);
	if (min == el->nbr)
		pb(a, b);
	else if (min == el->prev->nbr)
		(rra(a), pb(a, b));
	else if (min == el->next->nbr)
		(ra(a), pb(a, b));
	else if (min == el->next->next->nbr)
		(ra(a), ra(a), pb(a, b));
	treat3el(a);
	if ((*b)->nbr > (*a)->prev->nbr)
		(pa(a, b), ra(a));
	else if ((*b)->nbr < (*a)->nbr)
		pa(a, b);
	else if ((*b)->nbr < (*a)->next->nbr)
		(ra(a), pa(a, b), rra(a));
	else
		(rra(a), pa(a, b), ra(a));
}

void	treat5el(t_liste **a, t_liste **b)
{
	int		min1;
	int		min2;
	t_liste	*last;

	last = (*a)->prev;
	init_min(*a, &min1, &min2);
	if ((min1 == (*a)->prev->nbr && min2 == (*a)->prev->prev->nbr)
		|| (min2 == (*a)->prev->nbr && min1 == (*a)->prev->prev->nbr))
		(rra(a), rra(a), (pb(a, b)), pb(a, b));
	while (*a != last && (*a)->next->next->next != *a)
	{
		if ((*a)->nbr == min1 || (*a)->nbr == min2)
			pb(a, b);
		else
			ra(a);
	}
	if ((*a)->nbr == min1 || (*a)->nbr == min2)
		pb(a, b);
	if ((*b)->nbr > (*b)->next->nbr)
		(treat3el(a), pa(a, b), pa(a, b));
	else
		(treat3el_bis(a, b), pa(a, b), pa(a, b));
}

void	init_min(t_liste *a, int *min1, int *min2)
{
	t_liste	*last;

	last = a->prev;
	*min1 = INT_MAX;
	*min2 = INT_MAX;
	while (a != last)
	{
		if (a->nbr < *min1)
			*min1 = a->nbr;
		a = a->next;
	}
	if (a->nbr < *min1)
		*min1 = a->nbr;
	a = a->next;
	while (a != last)
	{
		if (a->nbr < *min2 && a->nbr != *min1)
			*min2 = a->nbr;
		a = a->next;
	}
	if (a->nbr < *min2 && a->nbr != *min1)
		*min2 = a->nbr;
}
