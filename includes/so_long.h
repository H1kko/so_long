/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:29:10 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/12 14:37:53 by maregnie         ###   ########.fr       */
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

void	is_map_valid(t_map *map);
void	ft_perror(char *str, char **map);
char	*get_next_line(int fd);
char	**get_map(char *argv);
char	**get_map_as_tab(t_map *lstmap);
void	ft_free(char **str);
void	verif_features(char **map);
int		*get_player_coos(char **map);
#endif
