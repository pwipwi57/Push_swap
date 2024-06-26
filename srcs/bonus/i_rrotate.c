/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_rrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:01:44 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	r_rotate(t_liste **a)
{
	if (*a == NULL)
		return ;
	*a = (*a)->prev;
	return ;
}

void	rra(t_liste **a)
{
	if (*a == NULL)
		return ;
	r_rotate(a);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_liste **b)
{
	if (*b == NULL)
		return ;
	r_rotate(b);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_liste **a, t_liste **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	r_rotate(a);
	r_rotate(b);
	ft_printf("rrr\n");
	return ;
}
