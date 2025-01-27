/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:29:10 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/21 11:01:28 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define WIDTH 32
# define HEIGHT 32

typedef struct s_item
{
	int			collectibles;
}				t_item;

typedef struct s_coos
{
	int			x;
	int			y;
}				t_coos;

typedef struct s_textures
{
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;
}					t_textures;

typedef struct s_sprite
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*coin;
	mlx_image_t	*exit;
}				t_sprite;

typedef struct s_game
{
	mlx_t		*mlx;
	t_textures	*textures;
	t_sprite	*sprite;
	char		**map;
	int			w_length;
	int			w_height;
	int			player_x;
	int			player_y;
	int			count;
}				t_game;

int			edge_checker(t_map *map);
void		check_floodfill(char **duped_map, char **map);
int			format_checker(t_map *map);
void		ft_perror(char *str, char **map);
char		*get_next_line(int fd);
char		**get_map(char *argv, t_game *game);
t_map		*get_map_as_list(char *argv);
char		**get_map_as_tab(t_map *lstmap);
void		ft_free(char **str);
int			free_game(t_game *game, int textures);
int			verif_features(char **map);
void		get_player_coos(char **map, t_game *game);
void		flood_fill(char **map, int collectibles, int x, int y);
char		**dup_map(char **map, int nb_line);
void		free_textures(t_game *game);
void		manage_floodfill(char **map, char *argv, int x, int y);
int			place_textures(t_game *game);
int			move_right(t_game *game);
int			move_down(t_game *game);
int			move_up(t_game *game);
int			move_left(t_game *game);
int			set_exit(t_game *game);
#endif
