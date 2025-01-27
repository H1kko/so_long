/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:49:11 by maregnie          #+#    #+#             */
/*   Updated: 2024/10/11 19:03:10 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	letter;

	letter = c;
	str = (char *)s;
	i = 0;
	while (i < ft_strlen(str)+1)
	{
		if (str[i] == letter)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
