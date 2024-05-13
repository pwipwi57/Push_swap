/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:20:41 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/11 19:22:45 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*parsing(int argc, char **argv)
{
	char	**nbr;

	if (argc == 1 || !argv[1][0])
		exit(EXIT_SUCCESS);
	else if (argc == 2 && checkpars1(argv[1]))
	{
		nbr = ft_split2(argv[1]);
		if (!nbr)
			exit(EXIT_FAILURE);
		return (treat(argc, nbr));
	}
	else if (checkpars2(argv + 1, argc))
		return (treat(argc, argv + 1));
	else
		ext_err();
	return (NULL);
}

t_liste	*treat(int argc, char **nbr)
{
	int		i;
	int		*tab;
	t_liste	**list;
	t_liste	*new;
	int		leng;

	list = NULL;
	i = -1;
	leng = calcleng(nbr);
	tab = ft_calloc(leng, sizeof(int));
	if (!tab)
		fr_chr_ex(nbr);
	while (nbr[++i])
	{
		if (verif_leng(nbr[i]))
			tab[i] = ft_atoi2(nbr[i]);
		else
			fr_int_chr_ex_error(argc, tab, nbr);
	}
	fr_chr_check_double(argc, nbr, tab, i);
	new = ft_lstnew2(tab[--i]);
	list = &new;
	while (i > 0 && list != NULL && *list != NULL)
		ft_lstadd_front2(list, ft_lstnew2(tab[--i]));
	return ((free(tab)), *list);
}

int	checkpars1(char *argvn)
{
	int	i;

	i = 1;
	if (!(ft_isdigit(argvn[0]) || (argvn[0] == '-' || argvn[0] == '+')))
		return (0);
	while (argvn[i])
	{
		if (argvn[i] == '-' || argvn[i] == '+')
			i++;
		while (ft_isdigit(argvn[i]))
			i++;
		if (argvn[i] == ' ' && argvn[i - 1] != ' ')
			i++;
		else if (argvn[i])
			return (0);
	}
	if (!ft_isdigit(argvn[i - 1]))
		return (0);
	return (1);
}

int	checkpars2(char **argv, int nb)
{
	int	i;

	while (nb-- > 1)
	{
		i = 0;
		if ((*argv)[i] == '-' || (*argv)[i] == '+')
			i++;
		while (ft_isdigit((*argv)[i]))
			i++;
		if ((*argv)[i] || i == 0 || !ft_isdigit((*argv)[i - 1]))
			return (0);
		argv++;
	}
	return (1);
}

int	verif_leng(char *nbri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((nbri[i] == '-' || nbri[i] == '+') && nbri[i + 1])
		i++;
	else
		return (0);
	while (nbri[i] == '0')
		i++;
	while (nbri[i + j])
		j++;
	if (j < 12)
		return (1);
	return (0);
}
