/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_treat3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 05:13:04 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:33 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treatflagp(unsigned long n, char *tab)
{
	ft_puthexmiltab(n, 2, tab);
	if (tab[0] == '(')
		return ;
	ft_rev_tab(tab + 2);
}

void	ft_treatflagu(unsigned int i, char *tab)
{
	ft_putuninttab(i, tab);
	ft_rev_tab(tab);
}

void	ft_treatflagx(unsigned int i, char *tab)
{
	ft_puthexmitab(i, 1, tab);
	ft_rev_tab(tab);
}

void	ft_treatflagx2(unsigned int i, char *tab)
{
	ft_puthexmajtab(i, 1, tab);
	ft_rev_tab(tab);
}
