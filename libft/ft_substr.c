/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:52:51 by maregnie          #+#    #+#             */
/*   Updated: 2024/10/09 11:55:37 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) || len + start >= ft_strlen(s))
		subs = malloc(ft_strlen(s) - start + 1);
	else
		subs = (char *)malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	while (s[i] && i < len + start)
	{
		subs[j] = (char)s[i];
		i++;
		j++;
	}
	subs[j] = 0;
	return (subs);
}
