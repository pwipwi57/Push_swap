/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:36:03 by tlamarch          #+#    #+#             */
/*   Updated: 2024/06/26 16:55:42 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../libft/libft.h"

typedef struct s_liste
{
	int				nbr;
	int				rank;
	struct s_liste	*prev;
	struct s_liste	*next;
}	t_liste;

// checker_bonus.c
int		main(int argc, char **argv);
t_liste	**checker(t_liste **a);
int		verif_instruct(t_liste **a, t_liste **b, char *line);
int		checksorted(t_liste **a, t_liste **b);

// ft_fr_2.c
void	fr_int_list_ex_error(int *tab);
void	fr_int_ex_error(int *tab);
void	fr_chr_check_double(int argc, char **nbr, int *tab, int i);

// ft_fr.c
void	fr_chr(char **nbr);
void	ext_err(void);
void	fr_chr_ex_error(char **nbr);
void	fr_chr_ex(char **nbr);
void	fr_int_chr_ex_error(int argc, int *tab, char **nbr);

// list.c
t_liste	*ft_lstnew2(int nbr);
void	ft_lstadd_front2(t_liste **lst, t_liste *new);
void	ft_lstdelone2(t_liste *lst);
void	ft_lstclear2(t_liste **lst);
void	del(t_liste *lst);

// parsing.c
t_liste	*parsing(int argc, char **argv);
t_liste	*treat(int argc, char **nbr);
int		checkpars1(char *argvn);
int		checkpars2(char **argv, int nb);
int		verif_leng(char *nbri);

// push_swap.c
int		push_swap(int argc, char **argv);

// push.c
void	push(t_liste **a, t_liste **b);
void	pa(t_liste **a, t_liste **b);
void	pb(t_liste **a, t_liste **b);
void	all_pa(t_liste **a, t_liste **b);

// q_insert_utils.c
void	choose(t_liste *a, t_liste *b, int *dir, int *nbr);
void	s_choose(t_liste *a, t_liste *el, int *best, int *nbr);
int		count_move1(t_liste *a, int nbr, int i);
int		count_move2(t_liste *a, int nbr, int i);
int		min_nbr(t_liste **a);

// q_insert.c
void	insert(t_liste **a, t_liste **b, int pivot, int min);
int		end_insert(t_liste **b, int min);
void	insert_pivot(t_liste **a, t_liste **b);
void	move(t_liste **a, t_liste **b, int dir, int nbr);
int		test_rank_el(t_liste *b);

// quicksort.c
void	quicksort(t_liste **a, t_liste **b, int rank);
int		test_4_last(t_liste **a);
void	s_quicksort(t_liste **a, t_liste **b, int pivot, int rank);
void	initpivot(t_liste **a, int *min, int *pivot_1, int *pivot_2);
int		max_nbr(t_liste **a);

// r_rotate.c
void	r_rotate(t_liste **a);
void	rra(t_liste **a);
void	rrb(t_liste **b);
void	rrr(t_liste **a, t_liste **b);

// rotate.c
void	rotate(t_liste **a);
void	ra(t_liste **a);
void	rb(t_liste **b);
void	rr(t_liste **a, t_liste **b);

// ft_split.c
int		ft_strlen2(char *str, char c);
int		count_tab2(char *st, char c, int *ntab);
void	*cop_ele2(char *src, char **nbr, char c);
char	**ft_split2(char *str);

// swap.c
void	swap(t_liste **a);
void	sa(t_liste **a);
void	sb(t_liste **b);
void	ss(t_liste **a, t_liste **b);

// treatment.c
void	treatment_ps(t_liste **a);
void	s_treatment(t_liste **a, t_liste **b);
int		lengstack(t_liste **a);

// treatment_2.c
void	treat3el(t_liste **a);
void	treat3el_bis(t_liste **a, t_liste **b);
void	treat4el(t_liste **a, t_liste **b);
void	treat5el(t_liste **a, t_liste **b);
void	init_min(t_liste *a, int *min1, int *min2);

// utils.c
int		ft_atoi2(char *nptr);
void	ft_check_double(int *tab, int leng);
int		calcleng(char **nbr);
void	remove_el(t_liste *lst);
int		test_ps(t_liste **a);

#endif