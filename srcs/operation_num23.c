/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_num23.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:53:24 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 20:16:01 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_type(t_stack *a, t_stack *b, int stack)
{
	int		i;
	t_stack	*tmp;

	if (stack == A)
		tmp = a;
	else
		tmp = b;
	i = ft_count_rrarrb(a, b, stack, tmp->nbr);
	while (tmp)
	{
		if (i > ft_count_rarb(a, b, stack, tmp->nbr))
			i = ft_count_rarb(a, b, stack, tmp->nbr);
		if (i > ft_count_rrarrb(a, b, stack, tmp->nbr))
			i = ft_count_rrarrb(a, b, stack, tmp->nbr);
		if (i > ft_count_rarrb(a, b, stack, tmp->nbr))
			i = ft_count_rarrb(a, b, stack, tmp->nbr);
		if (i > ft_count_rrarb(a, b, stack, tmp->nbr))
			i = ft_count_rrarb(a, b, stack, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
