/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fr_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:11:25 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	fr_int_list_ex_error(int *tab)
{
	free(tab);
	exit(EXIT_FAILURE);
}

void	fr_int_ex_error(int *tab)
{
	free(tab);
	ext_err();
}

void	fr_chr_check_double(int argc, char **nbr, int *tab, int i)
{
	if (argc < 3)
		fr_chr(nbr);
	ft_check_double(tab, i);
}
