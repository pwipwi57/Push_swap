/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:31:55 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:57 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *buf, ...)
{
	int		i;
	int		r;
	va_list	args;

	va_start(args, buf);
	i = 0;
	r = 0;
	while (buf[i])
	{
		while (buf[i] && buf[i] != '%')
		{
			ft_putchar(buf[i++], &r);
			if (r == -1)
				return (-1);
		}
		if (!buf[i])
			break ;
		treatment((buf + i), &args, &i, &r);
		if (r == -1)
			return (-1);
	}
	va_end(args);
	return (r);
}

void	treatment(const char *buf, va_list *args, int *i, int *r)
{
	if (checkbuf(buf[1], "cspdiuxX%"))
		treatnofl(buf, args, i, r);
	else if (checkbuf(buf[1], ".0-") && checkbuf(buf[2], "cpdiuxX%"))
	{
		treatnofl(buf + 1, args, i, r);
		(*i)++;
	}
	else if (checkbuf(buf[1], "# +") && checkbuf(buf[2], "cspdiuxX%"))
		treatfl1(buf, args, i, r);
	else if (condition3(buf))
		treatfl2(buf, args, i, r);
	else
		*i += 1;
	return ;
}

int	condition3(const char *buf)
{
	int	i;

	i = 2;
	if (!checkbuf(buf[1], "# +-0.123456789"))
		return (0);
	while (checkbuf(buf[i], "0.123456789"))
		i++;
	if (checkbuf(buf[i], "cspdiuxX%"))
		return (1);
	return (0);
}

int	checkbuf(char c, char *key)
{
	int	i;

	i = 0;
	while (key[i])
		if (key[i++] == c)
			return (1);
	return (0);
}

// int	main(void)
// {
// // // 	// char c = 'c';
// // // 	// char *s = "salut ca va ?";

// // // 	// printf("\n\n  Vrai printf\n\n");
// // // 	// printf("%c ; %s ; %p ; %d ; %i ; %u, %x 
// // ; %X ; %% \n%\n", c, s, &c, 42, 41, -1, 493, 493);
// // // 	// printf("\n\n  Mon printf \n\n");
// // // 	// printf("\n");
// // // 	// ft_printf("%c ; %s ; %p ; %d ; %i ;
// //  %u, %x ; %X ; %% \n%\n", c, s, &c, 42, 41, -1, 493, 493);
// 	printf("Salu\010t");
// 	ft_printf("Salu\010t");
// 	printf("\n");
// 	return (0);
// }
