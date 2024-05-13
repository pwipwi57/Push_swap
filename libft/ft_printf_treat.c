/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_treat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 05:13:04 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:40 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	treatnofl(const char *buf, va_list *args, int *i, int *r)
{
	if (buf[1] == '%')
		ft_putchar('%', r);
	else if (buf[1] == 'c')
		ft_putchar((char)va_arg(*args, int), r);
	else if (buf[1] == 's')
		ft_putstr(va_arg(*args, char *), r);
	else if (buf[1] == 'p')
		ft_puthexmil(va_arg(*args, unsigned long), 2, r);
	else if (buf[1] == 'd' || buf[1] == 'i')
		ft_putnbr(va_arg(*args, int), r);
	else if (buf[1] == 'u')
		ft_putunint(va_arg(*args, unsigned int), r);
	else if (buf[1] == 'x')
		ft_puthexmi(va_arg(*args, unsigned int), 1, r);
	else if (buf[1] == 'X')
		ft_puthexmaj(va_arg(*args, unsigned int), 1, r);
	*i += 2;
	return ;
}

void	treatfl1(const char *buf, va_list *args, int *i, int *r)
{
	if (buf[1] == '#' && buf[2] == 'x')
		ft_puthexmi(va_arg(*args, unsigned int), 2, r);
	else if (buf[1] == '#' && buf[2] == 'X')
		ft_puthexmaj(va_arg(*args, unsigned int), 2, r);
	else if ((buf[1] == ' ' || buf[1] == '+')
		&& (buf[2] == 'd' || buf[2] == 'i'))
		treatfldi(buf, va_arg(*args, int), r);
	else if ((buf[1] == ' ') && buf[2] == 's')
		ft_putstr(va_arg(*args, char *), r);
	*i += 3;
	return ;
}

void	treatfldi(const char *buf, int d, int *r)
{
	if (d < 0)
	{
		ft_putnbr(d, r);
		return ;
	}
	if (buf[1] == ' ')
		ft_putchar(' ', r);
	if (buf[1] == '+')
		ft_putchar('+', r);
	ft_putnbr(d, r);
}

void	treatfl2(const char *buf, va_list *args, int *i, int *r)
{
	int		j;
	int		s_field;
	int		s_tab;
	char	*tab;

	j = 2;
	tab = ft_calloc(1000, sizeof(char));
	if (tab == NULL)
	{
		*r = -1;
		return ;
	}
	s_field = calcfield(buf);
	while (checkbuf(buf[j], "-.0123456789"))
		j++;
	*i += j + 1;
	s_tab = treattab(tab, buf + j, args);
	printfield(buf, tab, r, s_field - s_tab);
	free(tab);
}

void	printfield(const char *buf, char *tab, int *r, int s_field)
{
	char	c;

	c = ' ';
	if (testprint(&tab, buf, &s_field, r))
		s_field--;
	if (*r == -1)
		return ;
	if (checkbuf(buf[1], ".0123456789"))
	{
		if (checkbuf(buf[1], ".0"))
			c = '0';
		while ((s_field--) > 0)
			ft_putchar(c, r);
		if (*r == -1)
			return ;
	}
	if (testprint(&tab, buf, &s_field, r))
		ft_putchar(0, r);
	else if (!(buf[1] == '.' && (buf[2] == 's')))
		ft_putstr(tab, r);
	if (*r == -1)
		return ;
	if (buf[1] == '-')
		while (s_field-- > 0)
			ft_putchar(c, r);
}
