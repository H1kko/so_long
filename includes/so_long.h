/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:29:10 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/13 16:53:20 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_item
{
	int			collectibles;
} 					t_item;

typedef	struct s_coos
{
	int			x;
	int			y;
}				t_coos;

void	is_map_valid(t_map *map);
void	ft_perror(char *str, char **map);
char	*get_next_line(int fd);
char	**get_map(char *argv);
char	**get_map_as_tab(t_map *lstmap);
void	ft_free(char **str);
int		verif_features(char **map);
t_coos	get_player_coos(char **map);
void	flood_fill(char **map, int collectibles, int x, int y);
char	**dup_map(char **map, int nb_line);
void	check_floodfill(char **duped_map, char **map);
#endif
