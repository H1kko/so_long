/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:30:29 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/20 12:49:08 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_exit(t_game *game)
{
	int			x;
	int			y;
	mlx_image_t	*tmp;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				tmp = game->sprite->exit;
				mlx_image_to_window(game->mlx, tmp, x * 32, y * 32);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	set_exit(t_game *game)
{
	int	coins;
	int	x;
	int	y;

	coins = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				coins++;
			x++;
		}
		y++;
	}
	if (coins == 0)
		return (put_exit(game));
	else
		return (0);
}

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

void	get_player_coos(char **map, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
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
