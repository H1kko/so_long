/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:30:39 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/14 10:47:41 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	memsize;

	if ((unsigned long long) nmemb * size > 4294967295)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		result = malloc(0);
		if (!result)
			return (NULL);
		return (result);
	}
	if ((long) nmemb < 0 || (long) size < 0)
		return (NULL);
	memsize = nmemb * size;
	result = malloc(memsize);
	if (!result)
		return (NULL);
	ft_bzero(result, memsize);
	return (result);
}
