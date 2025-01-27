/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:22:22 by maregnie          #+#    #+#             */
/*   Updated: 2024/11/15 17:10:07 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count_print;

	if (!str)
		return (-1);
	i = 0;
	count_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		if (str[i] == '%')
			count_print += check_char(&str[i++], args);
		else
			count_print += ft_putchar((char)str[i]);
		i++;
	}
	va_end(args);
	return (count_print);
}
