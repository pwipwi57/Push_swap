/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:55:29 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:30:16 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	char	c = '5';

// 	printf("%d\n", ft_isascii(c));
// 	printf("%d", isascii(c));
// 	return (0);
// }