/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 04:08:25 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:29 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunint(unsigned int n, int *r)
{
	char	c;

	if (*r == -1)
		return ;
	if (n < 10)
	{
		c = n + '0';
		ft_putchar(c, r);
		if (*r == -1)
			return ;
	}
	else
	{
		ft_putunint(n / 10, r);
		ft_putunint(n % 10, r);
	}
}

void	ft_putstr(char *s, int *r)
{
	int	i;

	if (s == NULL)
	{
		ft_putstr("(null)", r);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i++], r);
		if (*r == -1)
			return ;
	}
}

void	ft_putchar(char c, int *r)
{
	if ((write(1, &c, 1)) == -1)
		*r = -1;
	else
		*r = *r + 1;
}

void	ft_putnbr(int n, int *r)
{
	char	c;
	long	nb;

	nb = n;
	if (*r == -1)
		return ;
	if (n < 0)
	{
		ft_putchar('-', r);
		nb = nb * (-1);
		if (*r == -1)
			return ;
	}
	if (nb >= 0 && nb < 10)
	{
		c = nb + '0';
		ft_putchar(c, r);
		if (*r == -1)
			return ;
	}
	else
	{
		ft_putnbr(nb / 10, r);
		ft_putnbr(nb % 10, r);
	}
}

int	calcfield(const char *buf)
{
	if (checkbuf(buf[1], "123456789"))
		return (ft_atoi(buf + 1));
	else if (checkbuf(buf[1], " 0.-"))
		return (ft_atoi(buf + 2));
	return (0);
}
