/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:56:33 by maregnie          #+#    #+#             */
/*   Updated: 2024/11/07 15:20:46 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + 48);
	return (count);
}

int	ft_unsignedputnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n = n * -1;
	if (n > 9)
		count = ft_unsignedputnbr(n / 10);
	count += ft_putchar(n % 10 + 48);
	return (count);
}
