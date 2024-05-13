/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:33:28 by tlamarch          #+#    #+#             */
/*   Updated: 2023/11/12 21:49:39 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

static int	ft_strln(char *str, char charset)
{
	int	i;

	i = 0;
	while (is_sep(str[i], charset) == 0 && str[i])
		i++;
	return (i);
}

static int	count_tab(char *st, char ch, int *ntab)
{
	int	i;

	i = 0;
	(*ntab) = 0;
	if (!*st && !ch)
		return (0);
	if (ch == 0 || (*st && !ch))
	{
		(*ntab) = 1;
		return (1);
	}
	while (is_sep(st[i], ch))
		i++;
	if (st[i])
		(*ntab)++;
	while (st[i])
	{
		if (is_sep(st[i], ch) == 1 && is_sep(st[i + 1], ch) == 0 && st[i + 1])
			(*ntab)++;
		i++;
	}
	return (*ntab);
}

static void	*cop_ele(char *src, char **tab, char charset)
{
	int	i;

	i = 0;
	*tab = malloc(ft_strln(src, charset) + 1);
	while (is_sep(src[i], charset) == 0 && src[i])
	{
		(*tab)[i] = src[i];
		i++;
	}
	(*tab)[i] = '\0';
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		ntab;

	i = 0;
	j = 0;
	if ((!c && c != 0) || !s)
		return (NULL);
	tab = malloc(sizeof(char *) * ((count_tab((char *)s, c, &ntab)) + 1));
	if (!tab)
		return (NULL);
	tab[ntab] = 0;
	if (ntab == 0)
		return (tab);
	while (is_sep(s[i], c))
		i++;
	while (s[i])
	{
		if (is_sep(s[i], c) == 0
			&& (i == 0 || is_sep(s[i - 1], c)))
			cop_ele((char *)&s[i], &tab[j++], c);
		i++;
	}
	return (tab);
}
