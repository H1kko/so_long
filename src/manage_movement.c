/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:07:25 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/16 17:18:59 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(t_game *game)
{
	
	
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return;
// 	else
// 		game->playerpos->x++;
}