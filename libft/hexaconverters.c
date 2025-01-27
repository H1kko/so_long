/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaconverters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:42:51 by maregnie          #+#    #+#             */
/*   Updated: 2024/11/07 15:25:10 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaconvertupper(unsigned int n)
{
	static char	*hex = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (n >= 16)
		count = ft_hexaconvertupper(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_hexaconvertlower(unsigned int n)
{
	static char	*hex = "0123456789abcdef";
	int			count;

	count = 0;
	if (n >= 16)
		count = ft_hexaconvertlower(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

unsigned long	ft_hexaconvertpoint(unsigned long int n)
{
	static char	*hex = "0123456789abcdef";
	long int	count;
	static int	tmp = 0;

	count = 2;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (tmp == 0)
	{
		write(1, "0x", 2);
		tmp = 1;
	}
	if (n >= 16)
		count = ft_hexaconvertpoint(n / 16);
	count = count + ft_putchar(hex[n % 16]);
	tmp = 0;
	return (count);
}
