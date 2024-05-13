/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:38:38 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/15 23:29:36 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (8);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	char c = '.';
// 	printf("%d\n" , ft_isalnum(c));
// 	printf("%d" , isalnum(c));
// 	return 0;
// }