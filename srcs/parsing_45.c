/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_45.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:16:19 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 18:51:52 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d(char **arr);

int	atoi_update(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (sign == -1 || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (result > 2147483647)
			return (-1);
		else if (result < -2147483647)
			return (0);
		i++;
	}
	return (result * sign);
}

t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = atoi_update(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	free_2d(tmp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = NULL;
	if (argc < 2)
		exit(1);
	while (i < argc)
	{
		if ((argv[i][0] == '\0') || (contains_only_spaces(argv[i])))
			ft_error();
		i++;
	}
	if (argc == 2)
		a = parse_args_quoted(argv);
	else
		parse_individual_args(argc, argv, &a);
	return (a);
}

void	free_2d(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(arr);
}
