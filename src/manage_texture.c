/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:58:38 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/14 17:38:37 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_textures *get_textures(void)
{
	t_textures	*texture;
	
	texture = malloc(sizeof(t_textures));
	if (!texture)
		return (NULL);
	texture->ground = mlx_load_png("./textures/SHREK.png");
	if (!texture->ground)// || !texture->player || !texture->exit || !texture->wall
		//|| !texture->coin)
		return (NULL);
	return (texture);
}

int	put_textures(t_game *game)
{
	mlx_image_t	*tmp;

	tmp = game->textures->ground;
	mlx_image_to_window(game->mlx, tmp , 0, 0);
	return (1);
}