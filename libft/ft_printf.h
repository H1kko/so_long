/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:42 by maregnie          #+#    #+#             */
/*   Updated: 2024/11/15 16:55:36 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int				check_char(const char *next, va_list args);
int				ft_hexaconvertupper(unsigned int n);
int				ft_putchar(int c);
int				ft_hexaconvertupper(unsigned int n);
int				ft_hexaconvertlower(unsigned int n);
unsigned long	ft_hexaconvertpoint(unsigned long int n);
int				ft_putnbr(int n);
int				ft_unsignedputnbr(unsigned int n);
int				ft_printf(const char *str, ...);
int				printf_putstr(char *str);
#endif
