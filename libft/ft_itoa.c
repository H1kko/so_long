/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:14:48 by maregnie          #+#    #+#             */
/*   Updated: 2024/10/11 13:14:51 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nb_to_str;
	int		is_neg;
	int		len;

	len = nblen(n);
	is_neg = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		is_neg = -n;
	nb_to_str = (char *)malloc(sizeof(char) * (len + 1));
	if (nb_to_str != NULL)
	{
		nb_to_str[len--] = 0;
		if (n < 0)
			nb_to_str[0] = '-';
		else if (n == 0)
			nb_to_str[0] = '0';
		while (is_neg > 0)
		{
			nb_to_str[len--] = (char)(is_neg % 10 + 48);
			is_neg = is_neg / 10;
		}
	}
	return (nb_to_str);
}
