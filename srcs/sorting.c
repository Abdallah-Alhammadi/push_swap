/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:52:37 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 20:17:04 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort and push stacks until 3 elements left
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotate_type(*stack_a, *stack_b, A);
		while (i >= 0)
		{
			if (i == ft_count_rarb(*stack_a, *stack_b, A, tmp->nbr))
				i = ft_do_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_count_rrarrb(*stack_a, *stack_b, A, \
						tmp->nbr))
				i = ft_do_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_count_rarrb(*stack_a, *stack_b, A, tmp->nbr))
				i = ft_do_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_count_rrarb(*stack_a, *stack_b, A, tmp->nbr))
				i = ft_do_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

/* push all the elem from stack_a to stack_b, 
   until three elem, call ft_sort_three function */
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!ft_checksorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

/* push back the elements from stack_b
 to stack_a until stack_b is empty */
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type(*stack_a, *stack_b, B);
		while (i >= 0)
		{
			if (i == ft_count_rarb(*stack_a, *stack_b, B, tmp->nbr))
				i = ft_do_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_count_rarrb(*stack_a, *stack_b, B, tmp->nbr))
				i = ft_do_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_count_rrarrb(*stack_a, *stack_b, \
						B, tmp->nbr))
				i = ft_do_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_count_rrarb(*stack_a, *stack_b, B, tmp->nbr))
				i = ft_do_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

// sort the stack_a + bring min numb to the top
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_curr_pos(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				rra(stack_a, 0);
		}
	}
}

// sort 2
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a, 0);
		if (!ft_checksorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (ft_find_curr_pos(*stack_a, ft_max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
