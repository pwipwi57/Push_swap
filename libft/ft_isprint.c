/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:59:20 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:30:52 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (16384);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	char	c = 121;

// 	printf("%d\n", ft_isprint(c));
// 	printf("%d", isprint(c));
// 	return (0);
// }