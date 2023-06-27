/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:59:21 by abalhamm          #+#    #+#             */
/*   Updated: 2023/06/23 15:51:53 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			i += char_count(&s[i], c);
		}
	}
	return (count);
}

int	space_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		charlen;
	char	**tmp;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	tmp = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	j = space_count(&s[0], c);
	charlen = 0;
	while (i < words)
	{
		charlen = char_count(&s[j], c);
		tmp[i] = (char *)malloc(sizeof(char) * (charlen + 1));
		ft_strlcpy(tmp[i], &s[j], charlen + 1);
		j += charlen + space_count(&s[j + charlen], c);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
