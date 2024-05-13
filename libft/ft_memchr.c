/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:51:28 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 20:24:13 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (NULL);
	while (i <= (n - 2))
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&(((unsigned char *)s)[i]));
		i++;
	}
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return ((void *)&(((unsigned char *)s)[i]));
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// void	*ft_memchr(const void *s, int c, size_t n);

// int	main(void)
// {
// char	s1[] = {0 ,1 ,2 ,3 ,4 ,5};
// 	size_t	c = 2 + 256;

// 	printf("mienne : %s\n", (char *)ft_memchr(s1, c, 3));
// 	printf("Original : %s\n", (char *)memchr(s1, c, 3));
// 	return (0);
// }