/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:39:07 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 21:55:04 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while ((first[i] || second[i]) && i < length)
	{
		if (first[i] != second[i])
			return ((unsigned char)(first[i]) - (unsigned char)(second[i]));
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Salu£";
// 	char	s2[] = "Salut";

// 	printf("Original : %d\n", strncmp(s1, s2, 5));
// 	printf("La mienne : %d", ft_strncmp(s1, s2, 5));
// }
