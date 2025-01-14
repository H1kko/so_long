/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:18:57 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/14 17:38:07 by maregnie         ###   ########.fr       */
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
	game->w_length = ft_strlen(map[0]) * WIDTH;
	game->w_height = ft_tablen(map) * HEIGHT;
	game->mlx = mlx_init(game->w_length, game->w_height, "so_long", true);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;
	// int		i;
	// int		j;

	if (argc != 2)
		return (0);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (0);
	is_name_valid(argv[1]);
	map = get_map(argv[1]);
	init_game(map, game);
	if (!get_textures() || !put_textures(game))
	{
		free(game);	
		ft_perror("Textures loading failed", map);
	}
	//========print map=========//
	// while (map[i])
	// {
	// 	j = 0;
	// 	while (map[i][j])
	// 	{
	// 		printf("%c", map[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	//========print map=========//
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_loop(game->mlx);
	
	mlx_terminate(game->mlx);
	mlx_delete_image(game->mlx, game->textures)
	free(game);
	ft_free(map);
}
