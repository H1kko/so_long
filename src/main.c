/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:18:57 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/21 11:01:47 by maregnie         ###   ########.fr       */
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
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_D)
			move_right(game);
		else if (keydata.key == MLX_KEY_A)
			move_left(game);
		else if (keydata.key == MLX_KEY_W)
			move_up(game);
		else if (keydata.key == MLX_KEY_S)
			move_down(game);
		if (set_exit(game) && game->map[game->player_y][game->player_x] == 'E')
		{
			write(1, "You Win !", 9);
			free_game(game, 1);
		}
	}
}

void	mng_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	free_game(game, 1);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if (argc != 2)
		return (0);
	is_name_valid(argv[1]);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (0);
	map = get_map(argv[1], game);
	if (!map)
	{
		free(game);
		return (0);
	}
	if (!init_game(map, game) || !place_textures(game))
	{
		ft_putendl_fd("Error\nTexture loading failed", 1);
		free_game(game, 0);
	}
	mng_game(game);
}
