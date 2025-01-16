/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:18:57 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/16 17:13:48 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_name_valid(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b'
		|| argv[i - 4] != '.')
		ft_perror("Invalid name of map", NULL);
}

int	init_game(char **map, t_game *game)
{
	
	game->map = map;
	game->w_length = (ft_strlen(map[0]) - 1) * WIDTH;
	game->w_height = ft_tablen(map) * HEIGHT;
	game->mlx = mlx_init(game->w_length, game->w_height, "so_long", true);
	if (!game->mlx || !game->w_height || !game->w_length)
		return (0);
	return (1);
}
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	game = param;
	
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_D)
		move_right(game);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if (argc != 2)
		return (0);
	is_name_valid(argv[1]);
	map = get_map(argv[1]);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (0);
	if (!init_game(map, game) || !place_textures(game))
	{
		free(game);	
		ft_perror("Textures loading failed", map);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	free_textures(game);
	mlx_terminate(game->mlx);
	free(game);
	ft_free(map);
}
