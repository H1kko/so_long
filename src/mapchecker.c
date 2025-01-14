/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:25:12 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/14 13:56:07 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_features(char **map)
{
	int	tab[5];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	while (map[tab[3]])
	{
		tab[4] = 0;
		while (map[tab[3]][tab[4]])
		{
			if (map[tab[3]][tab[4]] == 'E')
				tab[2]++;
			if (map[tab[3]][tab[4]] == 'P')
				tab[0]++;
			if (map[tab[3]][tab[4]] == 'C')
				tab[1]++;
			tab[4]++;
		}
		tab[3]++;
	}
	if (tab[0] != 1 || tab[1] < 1 || tab[2] != 1)
		ft_perror("Wrong map config", map);
	return (tab[1]);
}

int	format_checker(t_map *map)
{
	int		len;
	t_map	*tmp;
	int		i;

	tmp = map;
	len = ft_strlen(map->content);
	while (map)
	{
		i = 0;
		while (map && map->content[i])
		{
			if ((map->content[i] != '0' && map->content[i] != '1'
					&& map->content[i] != 'P' && map->content[i] != 'C'
					&& map->content[i] != 'E' && map->content[i] != '\n')
				|| ft_strlen(map->content) != (size_t)len
				|| (map->content[0] != '1' || map->content[len - 2] != '1'))
			{
				ft_lstclear(&tmp, free);
				ft_perror("Map format error", NULL);
			}
			i++;
		}
		map = map->next;
	}
	return (len);
}

void	edge_checker(t_map *map)
{
	int		i;
	t_map	*tmp;

	i = 0;
	tmp = map;
	while (map->content[i] != '\n')
	{
		if (map->content[i++] != '1')
		{
			ft_lstclear(&tmp, free);
			ft_perror("Map format error", NULL);
		}
	}
	i = 0;
	map = ft_lstlast(map);
	while (map->content[i] != '\n')
	{
		if (map->content[i++] != '1')
		{
			ft_lstclear(&tmp, free);
			ft_perror("Map format error", NULL);
		}
	}
}

void	manage_floodfill(char **map, char *argv, int x, int y)
{
	t_map	*duped_lstmap;
	char	**duped_map;
	int		collectibles;

	collectibles = verif_features(map);
	duped_lstmap = (get_map_as_list(argv));
	duped_map = get_map_as_tab(duped_lstmap);
	flood_fill(duped_map, collectibles, x, y);
	check_floodfill(duped_map, map);
	ft_free(duped_map);
}
 