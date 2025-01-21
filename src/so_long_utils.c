/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:05:34 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/20 13:33:54 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_perror(char *str, char **map)
{
	int	i;

	i = 0;
	write(1, "Error\n", 6);
	while (str[i])
		write (1, &str[i++], 1);
	write(1, "\n", 1);
	if (map)
		ft_free(map);
	exit (-1);
}

void	free_sprite(mlx_image_t	*sprite, t_game *game)
{
	if (sprite)
		mlx_delete_image(game->mlx, sprite);
}

void	free_texture(mlx_texture_t *texture)
{
	if (texture)
		mlx_delete_texture(texture);
}

void	free_textures(t_game *game)
{
	free_texture(game->textures->coin);
	free_texture(game->textures->exit);
	free_texture(game->textures->player);
	free_texture(game->textures->ground);
	free_texture(game->textures->wall);
	if (game->sprite)
	{
		free_sprite(game->sprite->ground, game);
		free_sprite(game->sprite->wall, game);
		free_sprite(game->sprite->coin, game);
		free_sprite(game->sprite->exit, game);
		free_sprite(game->sprite->player, game);
		free(game->sprite);
	}
	if (game->textures)
		free(game->textures);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
