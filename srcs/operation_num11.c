/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_num11.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:50:28 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 20:17:38 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_rarb(t_stack *a, t_stack *b, int stack, int c)
{
	int	i;

	i = 0;
	if (stack == A)
	{
		i = ft_find_push_pos_b(b, c);
		if (i < ft_find_curr_pos(a, c))
			i = ft_find_curr_pos(a, c);
	}
	else if (stack == B)
	{
		i = ft_find_push_pos_a(a, c);
		if (i < ft_find_curr_pos(b, c))
			i = ft_find_curr_pos(b, c);
	}
	return (i);
}

int	ft_count_rrarrb(t_stack *a, t_stack *b, int stack, int c)
{
	int	i;

	i = 0;
	if (stack == A)
	{
		if (ft_find_push_pos_b(b, c))
			i = ft_lstsize(b) - ft_find_push_pos_b(b, c);
		if ((i < (ft_lstsize(a) - ft_find_curr_pos(a, c))) \
				&& ft_find_curr_pos(a, c))
			i = ft_lstsize(a) - ft_find_curr_pos(a, c);
	}
	else if (stack == B)
	{
		if (ft_find_push_pos_a(a, c))
			i = ft_lstsize(a) - ft_find_push_pos_a(a, c);
		if ((i < (ft_lstsize(b) - ft_find_curr_pos(b, c))) \
				&& ft_find_curr_pos(b, c))
			i = ft_lstsize(b) - ft_find_curr_pos(b, c);
	}
	return (i);
}

int	ft_count_rrarb(t_stack *a, t_stack *b, int stack, int c)
{
	int	i;

	i = 0;
	if (stack == A)
	{
		if (ft_find_curr_pos(a, c))
			i = ft_lstsize(a) - ft_find_curr_pos(a, c);
		i = ft_find_push_pos_b(b, c) + i;
	}
	else if (stack == B)
	{
		if (ft_find_push_pos_a(a, c))
			i = ft_lstsize(a) - ft_find_push_pos_a(a, c);
		i = ft_find_curr_pos(b, c) + i;
	}
	return (i);
}

int	ft_count_rarrb(t_stack *a, t_stack *b, int stack, int c)
{
	int	i;

	i = 0;
	if (stack == A)
	{
		if (ft_find_push_pos_b(b, c))
			i = ft_lstsize(b) - ft_find_push_pos_b(b, c);
		i = ft_find_curr_pos(a, c) + i;
	}
	else if (stack == B)
	{
		if (ft_find_curr_pos(b, c))
			i = ft_lstsize(b) - ft_find_curr_pos(b, c);
		i = ft_find_push_pos_a(a, c) + i;
	}
	return (i);
}
