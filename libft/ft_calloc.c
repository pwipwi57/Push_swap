/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:58:55 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 21:53:33 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = NULL;
	if (size == 0 || nmemb == 0)
	{
		ptr = malloc(1);
		return (ptr);
	}
	if ((nmemb * size) < size || (nmemb * size) < nmemb
		|| nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #include <stdint.h>

// int main(void)
// {
//     // int* p1 = calloc(4, sizeof(int));    
// allocate and zero out an array of 4 int
//     // int* p2 = calloc(1, sizeof(int[4])); 
// same, naming the array type directly
//     // int* p3 = calloc(4, sizeof *p3);     
// same, without repeating the type name

//     // if (p2)
//     // {
// 	// 	printf("Originale\n");
//     //     for (int n = 0; n < 4; ++n) // print the array
//     //         printf("p2[%d] == %d\n", n, p2[n]);
//     // }

//     // free(p1);
//     // free(p2);
//     // free(p3);

// 	// p1 = ft_calloc(4, sizeof(int));    
// allocate and zero out an array of 4 int
//     // p2 = ft_calloc(1, sizeof(int[4])); 
// same, naming the array type directly
//     // p3 = ft_calloc(4, sizeof *p3);     
// same, without repeating the type name

//     // if (p2)
//     // {
// 	// 	printf("Mine\n");
//     //     for (int n = 0; n < 4; ++n) // print the array
//     //         printf("p2[%d] == %d\n", n, p2[n]);
//     // }

//     // free(p1);
//     // free(p2);
//     // free(p3);

// 	void *p4;
// 	void *p5;

// 	p4 = calloc(SIZE_MAX, SIZE_MAX);
// 	p5 = ft_calloc(SIZE_MAX, SIZE_MAX);
// 	printf("%zu\n", SIZE_MAX);
// 	printf("Originale : %p\n\n", p4);
// 	printf("Mine : %p", p5);
// }