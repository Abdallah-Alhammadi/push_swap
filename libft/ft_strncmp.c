/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:08:26 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 15:52:51 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (!n)
		return (0);
	while (s1[x] && x < n - 1 && s1[x] == s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
