/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:58:49 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/11 18:16:32 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_liste	**a;
	t_liste	*elem;

	a = NULL;
	elem = (parsing(argc, argv));
	a = &elem;
	treatment_ps(a);
	if (!a)
		return (1);
	ft_lstclear2(a);
	return (0);
}
