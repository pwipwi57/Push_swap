/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:33:37 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/09 05:08:26 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_liste	**a;
	t_liste	*elem;

	a = NULL;
	elem = parsing(argc, argv);
	if (elem == NULL)
		return (1);
	a = &elem;
	a = checker(a);
	if (a == NULL)
		return (1);
	ft_lstclear2(a);
	return (0);
}

t_liste	**checker(t_liste **a)
{
	t_liste	**b;
	t_liste	*elnul;
	char	*line;

	elnul = NULL;
	b = &elnul;
	line = get_next_line(0);
	if (line == NULL)
		return (ft_lstclear2(a), ft_lstclear2(b), NULL);
	while (line != NULL)
	{
		if (!verif_instruct(a, b, line))
		{
			(ft_lstclear2(a), ft_lstclear2(b), free(line));
			return (write(2, "Error\n", 6), NULL);
		}
		free(line);
		line = get_next_line(0);
	}
	if (!checksorted(a, b))
		return (NULL);
	return (a);
}

int	verif_instruct(t_liste **a, t_liste **b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		push(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(b, a);
	else if (!ft_strncmp(line, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(line, "ss\n", 3))
		(swap(a), swap(b));
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		(rotate(a), rotate(b));
	else if (!ft_strncmp(line, "rra\n", 4))
		r_rotate(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		r_rotate(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		(r_rotate(a), r_rotate(b));
	else if (ft_strncmp(line, "\n", 1))
		return (0);
	return (1);
}

int	checksorted(t_liste **a, t_liste **b)
{
	t_liste	*last;

	if (*b != NULL)
		return (ft_lstclear2(b), ft_printf("KO\n"), 1);
	last = (*a)->prev;
	while (*a != last)
	{
		if ((*a)->nbr < (*a)->next->nbr)
			*a = (*a)->next;
		else
			return (ft_lstclear2(b), ft_printf("KO\n"), 1);
	}
	ft_printf("OK\n");
	return (1);
}
