/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:58:38 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/20 13:33:49 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_textures(t_game *game)
{
	t_textures	*texture;

	texture = ft_calloc(sizeof(t_textures), 1);
	if (!texture)
		return (0);
	texture->wall = mlx_load_png("./textures/wall.png");
	texture->player = mlx_load_png("./textures/character.png");
	texture->ground = mlx_load_png("./textures/ground.png");
	texture->coin = mlx_load_png("./textures/collectible.png");
	texture->exit = mlx_load_png("./textures/exit.png");
	game->textures = texture;
	if (!texture->wall || !texture->exit || !texture->player || !texture->wall
		|| !texture->coin)
		return (0);
	return (1);
}

int	convert_textures(t_game *game)
{
	t_sprite	*sprites;

	sprites = ft_calloc(sizeof(t_sprite), 1);
	if (!sprites)
		return (0);
	if (!get_textures(game))
	{
		free(sprites);
		return (0);
	}
	sprites->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	sprites->ground = mlx_texture_to_image(game->mlx, game->textures->ground);
	sprites->player = mlx_texture_to_image(game->mlx, game->textures->player);
	sprites->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
	sprites->coin = mlx_texture_to_image(game->mlx, game->textures->coin);
	game->sprite = sprites;
	return (1);
}

int	put_textures(t_game *game, char elem, int x, int y)
{
	mlx_image_t	*tmp;

	if (elem == '1')
		tmp = game->sprite->wall;
	else if (elem == 'C')
	{
		tmp = game->sprite->ground;
		if (mlx_image_to_window(game->mlx, tmp, x * 32, y * 32) == -1)
			return (0);
		tmp = game->sprite->coin;
	}
	else if (elem == 'E' || elem == 'P' || elem == '0')
		tmp = game->sprite->ground;
	else
		return (-1);
	if ((mlx_image_to_window(game->mlx, tmp, x * 32, y * 32)) == -1)
		return (0);
	return (1);
}

int	place_textures(t_game *game)
{
	int	x;
	int	y;

	if (!convert_textures(game))
		return (0);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!put_textures(game, game->map[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(game->mlx,
			game->sprite->player, game->player_x * 32, game->player_y * 32)
		== -1)
		return (0);
	return (1);
}
