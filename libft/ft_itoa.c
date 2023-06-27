/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:00:21 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 15:50:30 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	else if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*res;
	long	num;
	int		i;

	num = nb;
	i = nb_len(num);
	res = (char *)malloc (sizeof(char) * (nb_len(num) + 1));
	if (!res)
		return (NULL);
	res[i--] = '\0';
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		res[i--] = 48 + (num % 10);
		num /= 10;
	}
	return (res);
}
