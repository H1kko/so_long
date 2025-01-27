/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:14:48 by maregnie          #+#    #+#             */
/*   Updated: 2024/10/08 18:28:02 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	char	*copy;
	int		len;
	int		i;

	src = (char *)s;
	i = 0;
	len = ft_strlen((char *)s);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = (char)s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
