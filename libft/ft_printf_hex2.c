/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:17 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:44 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexmitab(unsigned int n, int mod, char *tab)
{
	char			*base;
	unsigned int	lenbase;

	lenbase = 16;
	base = "0123456789abcdef";
	if (mod == 2 && n != 0)
	{
		ft_putstrtab("0x", tab);
		tab += 2;
	}
	if (n < lenbase)
		*tab = base[n];
	else
	{
		ft_puthexmitab(n / lenbase, 1, tab + 1);
		ft_puthexmitab(n % lenbase, 1, tab);
	}
}

void	ft_puthexmiltab(unsigned long n, int mod, char *tab)
{
	char			*base;
	unsigned long	lenbase;

	lenbase = 16;
	base = "0123456789abcdef";
	if (n == 0 && mod == 2)
	{
		ft_putstrtab("(nil)", tab);
		return ;
	}
	if (mod == 2)
	{
		ft_putstrtab("0x", tab);
		tab += 2;
	}
	if (n < lenbase)
	{
		*tab = base[n];
	}
	else
	{
		ft_puthexmiltab(n / lenbase, 1, tab + 1);
		ft_puthexmiltab(n % lenbase, 1, tab);
	}
}

void	ft_puthexmajtab(unsigned int n, int mod, char *tab)
{
	char			*base;
	unsigned int	lenbase;

	lenbase = 16;
	base = "0123456789ABCDEF";
	if (mod == 2 && n != 0)
	{
		ft_putstrtab("0x", tab);
		tab += 2;
	}
	if (n < lenbase)
		*tab = base[n];
	else
	{
		ft_puthexmajtab(n / lenbase, 1, tab + 1);
		ft_puthexmajtab(n % lenbase, 1, tab);
	}
}
