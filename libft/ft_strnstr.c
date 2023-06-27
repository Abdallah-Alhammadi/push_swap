/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:32:42 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 20:32:21 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;

	if (*needle == '\0' || needle == haystack)
		return ((char *)haystack);
	if (!len)
		return (0);
	l = ft_strlen(needle);
	while (*haystack && len-- >= l)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, l) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
