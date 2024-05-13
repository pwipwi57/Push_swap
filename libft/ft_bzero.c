/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:31:11 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:29:06 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

// #include <string.h>

// int	main(void)
// {
// 	unsigned char	s[50] = "Salut la terre, comment ca va ?";
// 	unsigned char	s2[50] = "Salut la terre, comment ca va ?";

// 	bzero(s + 20, 9);
// 	printf("Original %s\n", s);
// 	ft_bzero(s2 + 20, 9);
// 	printf("Mienne %s", s2);
// 	return (0);
// }