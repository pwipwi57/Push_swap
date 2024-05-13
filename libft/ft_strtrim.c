/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:45:33 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/13 20:54:22 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkif(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*cpy;

	j = 0;
	k = 0;
	if (s1 == NULL)
		return (NULL);
	i = ft_strlen(s1) - 1;
	while (checkif(s1[i], (char *)set) && i != 0)
		i--;
	while (checkif(s1[j], (char *)set) && i != 0)
		j++;
	l = i - j;
	if (i == 0)
		return ((char *)(ft_calloc(1, sizeof(char))));
	cpy = malloc(((i - j) + 1) * (sizeof(char)) + 1);
	if (cpy == NULL)
		return (NULL);
	while ((k <= l) && i != 0)
		cpy[k++] = s1[j++];
	cpy[k] = 0;
	return (cpy);
}

// char	*ft_strtrim(char const *s1, char const *set);

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("ababweshabab", "ab"));
// 	return (0);
// }