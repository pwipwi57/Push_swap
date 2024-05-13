/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:05:33 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:33:17 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
	{
		if (!(s2[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!(little[0]))
		return ((char *)big);
	if (len == 0)
		return (NULL);
	if (big[0])
	{
		while (big[i] && i < len)
		{
			if (comp(&big[i], &little[0], len - i))
				return ((char *)&big[i]);
			else
				i++;
		}
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// #include "libft.h"

// int	main(void)
// {
// 	const char	s1[] = "Salut ca va ?";
// 	const char	s2[] = "ca ";

// 	printf("Original : %s\n", strnstr(s1, s2, 8));
// 	printf("La mienne : %s", ft_strnstr(s1, s2, 8));
// }