/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:33:53 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:33:34 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i--;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Avec double dose de picon";
// 	int		c = 111;

// 	printf("mienne : %s\n", ft_strrchr(s1, c));
// 	printf("Original : %s\n", strrchr(s1, c));
// 	return (0);
// }
