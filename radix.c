/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:12:27 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 04:32:00 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void	radixa(t_liste **a, t_liste **b, int gr, int unit)
// {
// 	if (test_radix(a, gr, unit))
// 		s_radixa(a, b, gr, unit);
// 	if (unit != 9)
// 		radixa(a, b, gr, unit + 1);
// 	else if (gr != 1000000000)
// 		radixb(a, b, gr * 10, 9);
// 	else
// 		all_pa(a, b);
// }

// void	s_radixa(t_liste **a, t_liste **b, int gr, int unit)
// {
// 	t_liste	*mem_a;

// 	mem_a = *a;
// 	while ((*a) != NULL && (*a)->next != mem_a)
// 	{
// 		if ((*a)->nbr / gr % 10 == unit)
// 		{
// 			if (mem_a == *a)
// 				mem_a = (*a)->next;
// 			pb(a, b);
// 		}
// 		else
// 			ra(a);
// 	}
// 	if ((*a) != NULL && (*a)->nbr / gr % 10 == unit)
// 		pb(a, b);
// 	else if ((*a))
// 		ra(a);
// }

// void	radixb(t_liste **a, t_liste **b, int gr, int unit)
// {
// 	if (test_radix(b, gr, unit))
// 		s_radixb(a, b, gr, unit);
// 	if (unit != -9)
// 		radixb(a, b, gr, unit - 1);
// 	else if (gr != 1000000000)
// 		radixa(a, b, gr * 10, -9);
// 	else
// 		all_pa(a, b);
// }

// void	s_radixb(t_liste **a, t_liste **b, int gr, int unit)
// {
// 	t_liste	*mem_a;

// 	mem_a = *b;
// 	while ((*b) != NULL && (*b)->next != mem_a)
// 	{
// 		if ((*b)->nbr / gr % 10 == unit)
// 		{
// 			if (mem_a == *b)
// 				mem_a = (*b)->next;
// 			pa(a, b);
// 		}
// 		else
// 			rb(b);
// 	}
// 	if ((*b) != NULL && (*b)->nbr / gr % 10 == unit)
// 		pa(a, b);
// 	else if (*b)
// 		rb(b);
// }

// int	test_radix(t_liste **b, int gr, int unit)
// {
// 	t_liste	*el;

// 	if (*b == NULL || max_nbrradix(b) < gr)
// 		return (0);
// 	el = *b;
// 	while ((el)->next != *b)
// 	{
// 		if (el->nbr / gr % 10 == unit)
// 			return (1);
// 		else
// 			el = el->next;
// 	}
// 	if (el->nbr / gr % 10 == unit)
// 		return (1);
// 	return (0);
// }

// int	max_nbrradix(t_liste **a)
// {
// 	long	max;
// 	long	temp;
// 	t_liste	*el;

// 	el = *a;
// 	max = el->nbr;
// 	if (max < 0)
// 		max = -max;
// 	el = el->next;
// 	while (el != *a)
// 	{
// 		temp = el->nbr;
// 		if (temp < 0)
// 			temp = -temp;
// 		if (temp > max)
// 			max = temp;
// 		el = el->next;
// 	}
// 	if (max > INT_MAX)
// 		max = INT_MAX;
// 	return ((int)max);
// }
