/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:16:20 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 21:38:21 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if ((len + (size_t)start) <= i)
		k = len;
	else if ((size_t)start > i)
		k = 0;
	else
		k = i - start;
	ptr = malloc(((k + 1) * sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	while (k != 0 && s[start + j] && j < len)
	{
		ptr[j] = s[start + j];
		j++;
	}	
	ptr[j] = '\0';
	return (ptr);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Avec double dose de picon";

// 	printf("mienne : %s\n", ft_substr(s1, 23, 25));
// 	return (0);
// }