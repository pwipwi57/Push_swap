/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:27:02 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/11 17:50:44 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(t_liste **a, t_liste **b, int rank)
{
	int		pivot_1;
	int		pivot_2;
	int		min;
	t_liste	*last;

	last = (*a)->prev;
	initpivot(a, &min, &pivot_1, &pivot_2);
	while ((*a) != last)
	{
		if ((*a)->nbr < pivot_2)
			s_quicksort(a, b, pivot_1, rank);
		else
			ra(a);
	}
	if ((*a)->nbr < pivot_2)
		s_quicksort(a, b, pivot_1, rank);
	if (test_4_last(a))
		quicksort(a, b, rank += 2);
	else
		s_treatment(a, b);
	insert(a, b, pivot_1, min);
	while ((*a)->prev->nbr < (*a)->nbr)
		rra(a);
}

int	test_4_last(t_liste **a)
{
	if ((*a)->next->next == *a || (*a)->next->next->next == *a
		|| (*a)->next->next->next->next == *a || (*a)->next == *a)
		return (0);
	return (1);
}

void	s_quicksort(t_liste **a, t_liste **b, int pivot, int rank)
{
	if ((*a)->nbr >= pivot)
	{
		(*a)->rank = rank + 1;
		(pb(a, b), rb(b));
	}
	else
	{
		(*a)->rank = rank;
		pb(a, b);
	}
}

void	initpivot(t_liste **a, int *min, int *pivot_1, int *pivot_2)
{
	int				max;
	unsigned int	dif;

	*min = min_nbr(a);
	max = max_nbr(a);
	dif = max - *min;
	*pivot_1 = *min + dif / 3;
	*pivot_2 = *min + 2 * dif / 3;
}

int	max_nbr(t_liste **a)
{
	int		max;
	t_liste	*el;

	max = (*a)->nbr;
	el = (*a)->next;
	while (el != *a)
	{
		if (el->nbr > max)
			max = el->nbr;
		el = el->next;
	}
	return (max);
}
