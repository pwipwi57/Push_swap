/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:45:07 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/07 21:17:54 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	unsigned char	s[50] = "Salut la terre, comment ca va ?";

// 	memset(s + 20, 48, 9);
// 	printf("Original %s\n", s);
// 	ft_memset(s + 20, 49, 10);
// 	printf("Mienne %s", s);
// 	return (0);
// }