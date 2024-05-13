/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:36:01 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:32:15 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&(s[i]));
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Avec double dose de picon";
// 	int		c = 0;

// 	printf("mienne : %s\n", ft_strchr(s1, c));
// 	printf("Original : %s\n", strchr(s1, c));
// 	return (0);
// }
