/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:05:34 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/14 10:28:52 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_perror(char *str, char **map)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
	write(1, "\n", 1);
	if (map)
		ft_free(map);
	exit (-1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
