/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:39:55 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 21:55:18 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		nb;
	long	nbl;

	i = 0;
	sign = 1;
	nbl = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nbl = nbl * 10 + (nptr[i] - 48);
		i++;
	}
	nb = nbl * sign;
	return (nb);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	printf("or : %d // mine : %d\n", atoi("4785956"), ft_atoi("4785956")); 
// 	printf("or : %d // mine : %d\n", atoi("4785956"), ft_atoi("4785956")); 
// 	printf("or : %d // mine : %d\n",
//  atoi("-2147483648"), ft_atoi("-2147483648")); 
// 	printf("or : %d // mine : %d\n", 
// 	atoi("    -4587954redf154"), ft_atoi("    -4587954redf154")); 
// 	printf("or : %d // mine : %d\n", 
// 	atoi(" 	 -8 457 154"), ft_atoi("          -8 457 154")); 
// 	printf("or : %d // mine : %d\n", atoi("r4d8f5487"), ft_atoi("r4d8f5487")); 
// 	printf("or : %d // mine : %d\n", 
// atoi("    - 874 5"), ft_atoi("    - 874 5")); 
// 	printf("or : %d // mine : %d\n", atoi("   1 "), ft_atoi("   1 ")); 
// 	printf("or : %d // mine : %d\n", atoi("-9451"), ft_atoi("-9451")); 
// }