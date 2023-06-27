/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:53:45 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 20:23:24 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include <limits.h>

# define A	1
# define B	2

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}	t_stack;

// main rules: sa,sb,pa,pb,ra,rb,rr,rra,rrb,rrr
void		ra(t_stack **a, int j);
void		rb(t_stack **b, int j);
void		sa(t_stack **a, int j);
void		pa(t_stack **a, t_stack **b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **a, int j);
void		ss(t_stack **a, t_stack **b, int j);
void		rr(t_stack **a, t_stack **b, int j);
void		r_r_r(t_stack **b, int j);
void		rrr(t_stack **a, t_stack **b, int j);
void		rrb(t_stack **b, int j);

//parsing
int			check_args(char **argv);
int			check_ft_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
int			sign(int c);
int			digit(int c);
int			space(int c);
int			ft_checksorted(t_stack *stack_a);

char		*ft_check(t_stack **a, t_stack **b, char *line);
t_stack		*ft_sub_process(char **argv);
t_stack		*ft_process(int argc, char **argv);
t_stack		*ft_parse(int argc, char **argv);
int			atoi_update(const char *str);
t_stack		*parse_args_quoted(char **argv);

bool		contains_only_spaces(const char *str);
void		parse_args(int argc, char **argv, t_stack **stack_a);
void		check_duplicates(char **argv, int argc);
void		split_numbers_separated_by_spaces(char **argv, \
		int *argc_ptr, char ***argv_ptr);
void		check_out_of_range_numbers(char **argv, int argc);
void		check_args_with_tabs(char **argv, int argc);
void		trim_spaces(char **argv, int argc);
void		parse_quoted_args(char **argv, t_stack **stack_a);
void		parse_individual_args(int argc, char **argv, t_stack **stack_a);
void		list_args(char **argv, t_stack **stack_a);
void		free_2d(char **arr);

//list
void		list_args(char **argv, t_stack **stack_a);
void		ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stack_new(int content);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
void		parse_individual_args(int argc, char **argv, t_stack **stack_a);
t_stack		t_args_quoted(char **argv);

// Sorting
void		ft_sort(t_stack **stack_a);
void		ft_sort_three(t_stack **stack_a);
void		ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);

// Operation number counter

int			ft_count_rarb(t_stack *a, t_stack *b, int stack, int c);
int			ft_count_rrarrb(t_stack *a, t_stack *b, int stack, int c);
int			ft_count_rrarb(t_stack *a, t_stack *b, int stack, int c);
int			ft_count_rarrb(t_stack *a, t_stack *b, int stack, int c);
int			ft_rotate_type(t_stack *a, t_stack *b, int stack);

// operation select
int			ft_do_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_do_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_do_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_do_rarrb(t_stack **a, t_stack **b, int c, char s);

// Check
void		ft_error(void);
void		ft_free(t_stack **lst);
void		ft_freestr(char **lst);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_find_curr_pos(t_stack *a, int nbr);
int			ft_find_push_pos_b(t_stack *stack_b, int nbr_push);
int			ft_find_push_pos_a(t_stack *a, int nbr);

#endif
