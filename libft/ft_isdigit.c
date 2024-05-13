/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:36:45 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:30:33 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (2048);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	char	c = '5';

// 	printf("%d\n", ft_isdigit(c));
// 	printf("%d", isdigit(c));
// 	return (0);
// }