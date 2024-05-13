/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:29:30 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 20:10:55 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	i = 0;
	if (src < dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// #include <string.h>

// int	main(void)
// {
// 	char	src[50] = "Salut la terre";
// 	// char	dest[50];
// 	char	src2[50] = "Salut la terre";
// 	// char	dest2[50];

// 	memmove(src + 1, src, 20);
// 	printf("Original %s\n", (unsigned char *)src);
// 	ft_memmove(src2 + 1, src2, 20);
// 	printf("Mienne %s", (unsigned char *)src2);
// 	return (0);
// }