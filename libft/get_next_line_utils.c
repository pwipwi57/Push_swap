/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:56:10 by tlamarch          #+#    #+#             */
/*   Updated: 2023/12/19 15:29:40 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcat(char *dest, char *src, int begin, int mod)
{
	size_t	lengdest;

	lengdest = ft_strlenp(dest, 0, 1);
	while (mod == 1 && src[begin])
	{
		dest[lengdest++] = src[begin];
		src[begin++] = 0;
		if (dest[lengdest - 1] == '\n')
			break ;
	}
	while (mod == 2 && begin < BUFFER_SIZE && src[begin])
	{
		dest[lengdest++] = src[begin];
		src[begin++] = 0;
		if (dest[lengdest - 1] == '\n')
			break ;
	}
	dest[lengdest] = '\0';
	return ;
}

void	ft_test_backn(char **tbuf, char *buf, int begin, ssize_t *cr)
{
	int	i;

	i = begin;
	while (i < BUFFER_SIZE)
		if (buf[i++] == '\n')
			*cr = 0;
	*tbuf = ft_realloc(*tbuf, buf, begin);
	if (*tbuf == NULL)
		*cr = 0;
}

void	initvar(char *tempbuf, ssize_t *charread)
{
	tempbuf[0] = 0;
	*charread = 1;
}
