/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:07:25 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/21 13:44:03 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_instance(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game->sprite->coin->count)
	{
		if (game->sprite->coin->instances[i].enabled
			&& game->sprite->coin->instances[i].x == x * 32
			&& game->sprite->coin->instances[i].y == y * 32)
		{
			game->sprite->coin->instances[i].enabled = 0;
			return ;
		}
		i++;
	}
}

int	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return (0);
	else
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->player_x++;
		game->sprite->player->instances[0].x = game->player_x * 32;
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->map[game->player_y][game->player_x] = '0';
			find_instance(game, game->player_x, game->player_y);
		}
	}
	return (1);
}

int	move_left(t_game *game )
{
	if (game->map[game->player_y][game->player_x - 1] == '1')
		return (0);
	else
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->player_x--;
		game->sprite->player->instances[0].x = game->player_x * 32;
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->map[game->player_y][game->player_x] = '0';
			find_instance(game, game->player_x, game->player_y);
		}
	}
	return (1);
}

int	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '1')
		return (0);
	else
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->player_y--;
		game->sprite->player->instances[0].y = game->player_y * 32;
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->map[game->player_y][game->player_x] = '0';
			find_instance(game, game->player_x, game->player_y);
		}
	}
	return (1);
}

int	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '1')
		return (0);
	else
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->player_y++;
		game->sprite->player->instances[0].y = game->player_y * 32;
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->map[game->player_y][game->player_x] = '0';
			find_instance(game, game->player_x, game->player_y);
		}
	}
	return (1);
}
