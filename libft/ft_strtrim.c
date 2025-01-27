/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:50:07 by maregnie          #+#    #+#             */
/*   Updated: 2024/10/10 10:48:44 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_character(char c, const char *set)
{
	int	i;

	i = 0;
	while (c != set[i] && set[i])
		i++;
	if (c == set[i])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (has_character(s1[start], set))
		start++;
	while (has_character(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
