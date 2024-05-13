/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:09:40 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:26 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuninttab(unsigned int n, char *tab)
{
	if (n < 10)
		*tab = n + '0';
	else
	{
		ft_putuninttab(n / 10, tab + 1);
		ft_putuninttab(n % 10, tab);
	}
}

void	ft_putstrtab(char *s, char *tab)
{
	int	i;

	if (s == NULL)
	{
		ft_putstrtab("(null)", tab);
		return ;
	}
	i = 0;
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
}

void	ft_putnbrtab(int n, char *tab)
{
	long	nb;
	int		sign;

	sign = 0;
	nb = n;
	if (n < 0)
	{
		sign = 1;
		nb = nb * (-1);
	}
	if (nb >= 10)
	{
		ft_putnbrtab(nb / 10, tab + 1);
		ft_putnbrtab(nb % 10, tab);
	}
	else
		*tab = nb + '0';
	if (sign)
	{
		while (*tab)
			tab++;
		*tab = '-';
	}
}

void	ft_rev_tab(char *tab)
{
	int	i;
	int	exc;
	int	size;

	if (!tab)
		return ;
	i = 0;
	size = 0;
	while (tab[size])
		size++;
	size--;
	while (i <= (size))
	{
		exc = tab[i];
		tab[i] = tab[size];
		tab[size] = exc;
		i++;
		size--;
	}
}
