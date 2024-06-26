/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:59:49 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_atoi2(char *nptr)
{
	int		i;
	int		sign;
	long	nbl;

	i = 0;
	sign = 1;
	nbl = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nbl = nbl * 10 + (nptr[i] - 48);
		i++;
	}
	nbl = nbl * sign;
	if (INT_MIN > nbl || INT_MAX < nbl)
		ext_err();
	return ((int)nbl);
}

void	ft_check_double(int *tab, int leng)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < leng - 1)
	{
		j = i + 1;
		while (j < leng)
		{
			if (tab[i] == tab [j])
				fr_int_ex_error(tab);
			j++;
		}
		i++;
	}
	return ;
}

int	calcleng(char **nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
		i++;
	return (i);
}

void	remove_el(t_liste *lst)
{
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	lst->next = lst;
	lst->prev = lst;
}

int	test_ps(t_liste **a)
{
	t_liste	*el;

	if (!a)
		return (0);
	el = (*a)->next;
	while (el->nbr > el->prev->nbr)
		el = el->next;
	if (el == *a)
		return (1);
	return (0);
}
