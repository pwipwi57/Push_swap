/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:43:39 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:31:40 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		n--;
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}

// #include <string.h>

// int	main(void)
// {
// 	char	src[50] = "Salut la terre";
// 	char	src2[50] = "Salut la terre";

// 	memcpy(src + 1, src, 10);
// 	printf("Original %s\n", (unsigned char *)src);
// 	ft_memcpy(src2 + 1, src2, 10);
// 	printf("Mienne %s", (unsigned char *)src2);
// 	return (0);
// }