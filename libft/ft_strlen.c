/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:18:01 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:32:58 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// int main(void)
// {
// 	char *c = "hg";
// 	printf("%zu\n" , ft_strlen(c));
// 	printf("%zu" , strlen(c));
// 	return 0;
// }