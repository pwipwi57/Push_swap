/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:51:18 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	fr_chr(char **nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		free(nbr[i]);
		i++;
	}
	free(nbr);
}

void	ext_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	fr_chr_ex_error(char **nbr)
{
	fr_chr(nbr);
	ext_err();
}

void	fr_chr_ex(char **nbr)
{
	fr_chr(nbr);
	exit(EXIT_FAILURE);
}

void	fr_int_chr_ex_error(int argc, int *tab, char **nbr)
{
	free(tab);
	if (argc < 3)
		fr_chr_ex_error(nbr);
	else
		ext_err();
}
