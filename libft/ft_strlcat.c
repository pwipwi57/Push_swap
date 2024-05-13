/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:27:46 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:32:45 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	lengsrc;
	size_t	lengdest;

	lengsrc = ft_strlen(src);
	if (size == 0)
		return (lengsrc);
	lengdest = ft_strlen(dest);
	if (size <= lengdest)
		return (lengsrc + size);
	i = 0;
	j = 0;
	if (size == 0)
		return (lengsrc);
	i = lengdest;
	while (src[j] && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (lengdest + lengsrc);
}

// #include <string.h>
// #include <stdio.h>
// #include <bsd/string.h>

// int	main(void)
// {
// 	char			s1[] = "Avec double dose de picon";
// 	char			s2[100] = "Une biere SVP ! ";
// 	unsigned int	my = ft_strlcat(s2, s1, 0);
// 	char			s3[100] = "Une biere SVP ! ";
// 	unsigned int	or = strlcat(s3, s1, 0);

// 	printf("Moi// Value returned: %d\n", my);
// 	if (my > 20)
// 		puts("String truncated");
// 	else
// 		puts("String was fully copied");
// 	printf("Original// Value returned: %d\n", or);
//         if (or > 20)
//                 puts("String truncated");
//         else
//                 puts("String was fully copied");
// }
// // gcc -o prog ft_strlcat.c -lbsd

// #include <string.h>
// #include <stddef.h>

// int		main(void)
// {
// 	char	*dest;

// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	memset(dest, 'r', 15);
// 	printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	write(1, "\n", 1);
// }