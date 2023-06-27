/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_22.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:31:28 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 17:57:42 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

t_stack	*parse_args_quoted(char **argv)
{
	t_stack	*stack_a;
	char	**tmp;

	stack_a = NULL;
	tmp = ft_split(argv[1], 32);
	list_args(tmp, &stack_a);
	ft_freestr(tmp);
	free(tmp);
	return (stack_a);
}

void	parse_individual_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		list_args(tmp, stack_a);
		free_2d(tmp);
		i++;
	}
}

void	list_args(char **argv, t_stack **stack_a)
{
	long	i;
	long	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = atoi_update(argv[i]);
		if (j != -1)
			ft_add_back(stack_a, ft_stack_new((j)));
		i++;
	}
}
