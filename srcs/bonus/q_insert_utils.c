/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_insert_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:25:30 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	choose(t_liste *a, t_liste *b, int *dir, int *nbr)
{
	int		best;
	int		move;
	int		i;

	i = 1;
	*dir = 1;
	best = 100000;
	s_choose(a, b, &best, nbr);
	b = b->prev;
	while (b->rank >= b->next->rank && i < best)
	{
		move = count_move2(a, b->nbr, i);
		if (move < best)
		{
			*dir = 0;
			*nbr = b->nbr;
			best = move;
		}
		i++;
		b = b->prev;
	}
}

void	s_choose(t_liste *a, t_liste *el, int *best, int *nbr)
{
	int	move;
	int	i;

	i = 0;
	while (el->rank >= el->prev->rank && i < *best)
	{
		move = count_move1(a, el->nbr, i);
		if (move < *best)
		{
			*best = move;
			*nbr = el->nbr;
		}
		i++;
		el = el->next;
	}
}

int	count_move1(t_liste *a, int nbr, int i)
{
	int	j;

	j = 0;
	if (nbr > a->nbr)
	{
		while (nbr > a->nbr)
		{
			j++;
			a = a->next;
		}
		if (j > i)
			i = j;
	}
	else if (a->prev->nbr > nbr && a->prev->nbr < a->nbr)
	{
		while (nbr < a->prev->nbr && a->prev->nbr < a->nbr)
		{
			j++;
			a = a->prev;
		}
		i = i + j;
	}
	return (i);
}

int	count_move2(t_liste *a, int nbr, int i)
{
	int	j;

	j = 0;
	if (nbr > a->nbr)
	{
		while (nbr > a->nbr)
		{
			j++;
			a = a->next;
		}
		i = i + j;
	}
	else if (a->prev->nbr > nbr && a->prev->nbr < a->nbr)
	{
		while (nbr < a->prev->nbr && a->prev->nbr < a->nbr)
		{
			j++;
			a = a->prev;
		}
		if (j > i)
			i = j;
	}
	return (i);
}

int	min_nbr(t_liste **a)
{
	long	min;
	t_liste	*el;

	min = (*a)->nbr;
	el = (*a)->next;
	while (el != *a)
	{
		if (el->nbr < min)
			min = el->nbr;
		el = el->next;
	}
	return (min);
}
