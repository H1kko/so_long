/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:21:48 by maregnie          #+#    #+#             */
/*   Updated: 2024/10/08 17:29:28 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	c_cast;

	i = 0;
	str = (unsigned char *)s;
	c_cast = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == (c_cast))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
