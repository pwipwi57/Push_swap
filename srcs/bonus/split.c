/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:33:21 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:38 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strlen2(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

int	count_tab2(char *st, char c, int *ntab)
{
	int	i;

	i = 0;
	(*ntab) = 0;
	if (!*st)
		return (0);
	if (st[i])
		(*ntab)++;
	while (st[i])
	{
		if (st[i] == c && st[i + 1])
			(*ntab)++;
		i++;
	}
	return (*ntab);
}

void	*cop_ele2(char *src, char **nbr, char c)
{
	int	i;

	i = 0;
	*nbr = malloc(ft_strlen2(src, c) + 1);
	if (!(*nbr))
		return (NULL);
	while (src[i] != c && src[i])
	{
		(*nbr)[i] = src[i];
		i++;
	}
	(*nbr)[i] = '\0';
	return (0);
}

char	**ft_split2(char *str)
{
	char	**nbr;
	int		i;
	int		j;
	int		ntab;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	checkpars1(str);
	nbr = malloc(sizeof(char *) * ((count_tab2(str, ' ', &ntab)) + 1));
	if (!nbr)
		return (NULL);
	nbr[ntab] = 0;
	if (ntab == 0)
		return (nbr);
	while (str[i])
	{
		if ((str[i] != ' ') && (i == 0 || str[i - 1] == ' '))
			cop_ele2(str + i, &nbr[j++], ' ');
		if (j > 0 && !(nbr[j - 1]))
			fr_chr_ex(nbr);
		i++;
	}
	return (nbr);
}
