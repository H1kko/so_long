/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:29:10 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/14 17:27:38 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h> // vfjkdbhsfkdghsfjkdghsfdjklghfdjklghfdjkghfdkjlgfdhgjkfdghjkdsfghfjkdgsfhdjkl

#define WIDTH 32
#define HEIGHT 32

typedef struct s_item
{
	int			collectibles;
} 					t_item;

typedef	struct s_coos
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
}					t_sprite;

typedef struct s_game
{
	mlx_t		*mlx;
	t_textures	*textures;
	t_sprite	*sprite;
	char		**map;
	int			w_length;
	int			w_height;
}				t_game;

void		edge_checker(t_map *map);
int			format_checker(t_map *map);
void		ft_perror(char *str, char **map);
char		*get_next_line(int fd);
char		**get_map(char *argv);
t_map		*get_map_as_list(char *argv);
char		**get_map_as_tab(t_map *lstmap);
void		ft_free(char **str);
int			verif_features(char **map);
t_coos		get_player_coos(char **map);
void		flood_fill(char **map, int collectibles, int x, int y);
char		**dup_map(char **map, int nb_line);
void		check_floodfill(char **duped_map, char **map);
t_textures	*get_textures(void);
int			put_textures(t_game *game);
void		manage_floodfill(char **map, char *argv, int x, int y);
#endif
