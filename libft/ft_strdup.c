/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:08:39 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:32:26 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		srcleng;
	char	*copy;

	copy = NULL;
	srcleng = 0;
	i = 0;
	srcleng = ft_strlen(s) + 1;
	copy = malloc(srcleng);
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*copy;
// 	char	*original;

// 	copy = ft_strdup("Test");
// 	original = strdup("Test");
// 	printf("%s\n", strcmp(original, copy) == 0 ?
// 			"OK" :
// 			"Fail");
// 	free (copy);
// }
