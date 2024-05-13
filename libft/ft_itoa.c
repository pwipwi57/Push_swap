/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:50:39 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 20:08:13 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calclen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	exc;

	if (!tab || size < 1)
		return ;
	i = 0;
	size = size - 1;
	while (i <= (size))
	{
		exc = tab[i];
		tab[i] = tab[size];
		tab[size] = exc;
		i++;
		size--;
	}
}

static char	*sign_and_rev(int i, int sign, char *res)
{
	if (sign == -1)
		res[i++] = '-';
	res[i] = '\0';
	ft_rev_int_tab(res, i);
	return (res);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		i;
	int		sign;
	char	*res;

	nbr = n;
	i = 0;
	sign = 1;
	res = malloc(calclen(nbr) + 1);
	if (res == NULL)
		return (NULL);
	if (nbr < 0)
	{
		sign = -sign;
		nbr = nbr * (-1);
	}
	if (nbr == 0)
		res[i++] = '0';
	while (nbr > 0)
	{
		res[i++] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	res = sign_and_rev(i, sign, res);
	return (res);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	return (0);
// }
