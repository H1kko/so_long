/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:30:29 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/14 13:56:27 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_floodfill(char **duped_map, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (duped_map[i])
	{
		j = 0;
		while (duped_map[i][j])
		{
			if (duped_map[i][j] == 'C' || duped_map[i][j] == 'E')
			{
				ft_free(map);
				ft_perror("No correct path exists", duped_map);
			}
			j++;
		}
		i++;
	}
}

t_coos	get_player_coos(char **map)
{
	int		i;
	int		j;
	t_coos	point;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				point.x = j;
				point.y = i;
			}
			j++;
		}
		i++;
	}
	return (point);
}

void	flood_fill(char **map, int collectibles, int x, int y)
{
	int	exit;
	int	total_collectibles;

	total_collectibles = collectibles;
	exit = 1;
	if (!map || map[y][x] == '1' || x > 500 || y > 500 || map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_fill(map, collectibles, x + 1, y);
	flood_fill(map, collectibles, x - 1, y);
	flood_fill(map, collectibles, x, y + 1);
	flood_fill(map, collectibles, x, y - 1);
}
