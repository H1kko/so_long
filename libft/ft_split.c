/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:26:46 by maregnie          #+#    #+#             */
/*   Updated: 2024/12/08 15:18:16 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	find_size(char const *str, char sep, int pos)
{
	int	i;

	i = pos;
	while (str[i] != sep && str[i])
		i++;
	return (i - pos);
}

static char	**free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs[i]);
	free(strs);
	return (NULL);
}

static char	**splited_split(char const *s, char c, char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			strs[j] = malloc(sizeof(char) * (find_size(s, c, i) + 1));
			if (strs[j] == NULL)
				return (free_all(strs));
			while (s[i] != c && s[i])
				strs[j][k++] = s[i++];
			strs[j++][k] = '\0';
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s || s[0] == '\0')
		return (NULL);
	strs = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	else
		return (splited_split(s, c, strs));
}
