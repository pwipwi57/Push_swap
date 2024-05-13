/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:17 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:47 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexmi(unsigned int n, int mod, int *r)
{
	char				*base;
	unsigned int		lenbase;

	lenbase = 16;
	base = "0123456789abcdef";
	if (mod == 2 && n != 0)
		ft_putstr("0x", r);
	if (*r == -1)
		return ;
	if (n < lenbase)
	{
		ft_putchar(base[n], r);
		if (*r == -1)
			return ;
	}
	else
	{
		ft_puthexmi(n / lenbase, 1, r);
		ft_puthexmi(n % lenbase, 1, r);
	}
}

void	ft_puthexmil(unsigned long n, int mod, int *r)
{
	char				*base;
	unsigned long		lenbase;

	lenbase = 16;
	base = "0123456789abcdef";
	if (n == 0 && mod == 2)
	{
		ft_putstr("(nil)", r);
		return ;
	}
	if (mod == 2)
		ft_putstr("0x", r);
	if (*r == -1)
		return ;
	if (n < lenbase)
	{
		ft_putchar(base[n], r);
		if (*r == -1)
			return ;
	}
	else
	{
		ft_puthexmil(n / lenbase, 1, r);
		ft_puthexmil(n % lenbase, 1, r);
	}
}

void	ft_puthexmaj(unsigned int n, int mod, int *r)
{
	char			*base;
	unsigned int	lenbase;

	lenbase = 16;
	base = "0123456789ABCDEF";
	if (mod == 2 && n != 0)
		ft_putstr("0X", r);
	if (*r == -1)
		return ;
	if (n < lenbase)
	{
		ft_putchar(base[n], r);
		if (*r == -1)
			return ;
	}
	else
	{
		ft_puthexmaj(n / lenbase, 1, r);
		ft_puthexmaj(n % lenbase, 1, r);
	}
}
