/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:55:09 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	treatment_ps(t_liste **a)
{
	int		leng;
	t_liste	**b;
	t_liste	*empty;

	empty = NULL;
	b = &empty;
	if (test_ps(a))
		return ;
	leng = lengstack(a);
	if (leng <= 5)
		s_treatment(a, b);
	else
		quicksort(a, b, 0);
}

void	s_treatment(t_liste **a, t_liste **b)
{
	int	leng;

	leng = lengstack(a);
	if (leng == 2 && (*a)->nbr > (*a)->next->nbr)
		sa(a);
	else if (leng == 3)
		treat3el(a);
	else if (leng == 4)
		treat4el(a, b);
	else if (leng == 5)
		treat5el(a, b);
}

int	lengstack(t_liste **a)
{
	int		i;
	t_liste	*temp;

	i = 1;
	temp = *a;
	while (temp->next != *a)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
