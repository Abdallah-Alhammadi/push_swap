/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:01:00 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 15:53:02 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lst;

	lst = NULL;
	while (*s)
	{
		if (*s == (char)c)
			lst = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (lst);
}
