/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:12:08 by maregnie          #+#    #+#             */
/*   Updated: 2024/11/15 17:00:24 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, (unsigned char *)&c, 1);
	return (1);
}

int	printf_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	check_char(const char *next, va_list args)
{
	int	i;

	i = 0;
	if (next[1] == 'd' || next[1] == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (next[1] == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (next[1] == 's')
		i += printf_putstr(va_arg(args, char *));
	else if (next[1] == 'p')
		i += ft_hexaconvertpoint(va_arg(args, unsigned long int));
	else if (next[1] == '%')
		i += ft_putchar(37);
	else if (next[1] == 'u')
		i += ft_unsignedputnbr(va_arg(args, unsigned int));
	else if (next[1] == 'x')
		i += ft_hexaconvertlower(va_arg(args, unsigned int));
	else if (next[1] == 'X')
		i += ft_hexaconvertupper(va_arg(args, unsigned int));
	else
		i = -1;
	return (i);
}
