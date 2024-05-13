/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_treat2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 05:13:04 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:37 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	treattab(char *tab, const char *buf, va_list *args)
{
	int	i;

	i = 0;
	if (buf[0] == '%')
		tab[0] = '%';
	else if (buf[0] == 'c')
		tab[0] = (char)va_arg(*args, int);
	else if (buf[0] == 's')
		ft_putstrtab(va_arg(*args, char *), tab);
	else if (buf[0] == 'p')
		ft_treatflagp(va_arg(*args, unsigned long), tab);
	else if (buf[0] == 'd' || buf[0] == 'i')
		ft_tabcpy(tab, ft_itoa(va_arg(*args, int)));
	else if (buf[0] == 'u')
		ft_treatflagu(va_arg(*args, unsigned int), tab);
	else if (buf[0] == 'x')
		ft_treatflagx(va_arg(*args, unsigned int), tab);
	else if (buf[0] == 'X')
		ft_treatflagx2(va_arg(*args, unsigned int), tab);
	while (tab[i])
		i++;
	return (i);
}

void	ft_tabcpy(char *tab, char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		tab[i] = nbr[i];
		i++;
	}
	free(nbr);
	return ;
}

int	testprint(char **tab, const char *buf, int *s_field, int *r)
{
	int	i;

	i = 1;
	while (checkbuf(buf[i], ".-0123456789"))
		i++;
	if (((buf[i] == 'c') && *tab[0] == 0))
		return (1);
	else if ((*tab)[0] == '-' && checkbuf(buf[1], "0.")
		&& checkbuf(buf[i], "di"))
	{
		ft_putchar('-', r);
		(*tab)++;
		if (buf[1] == '.')
			(*s_field)++;
		return (0);
	}
	else if (buf[i] == 's' && (buf[1] == '.' || buf[2] == '.'))
	{
		*s_field = 0;
		if ((*tab)[0])
			(*tab)[ft_atoi(buf + 2)] = 0;
	}
	return (0);
}
