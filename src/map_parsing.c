/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:55:34 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/17 16:24:09 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_game(t_game *game, int textures)
{
	mlx_t	*tmp;

	tmp = game->mlx;
	if (textures)
		free_textures(game);
	ft_free(game->map);
	free(game);
	if (!tmp)
		return (0);
	mlx_terminate(tmp);
	exit (-1);
	return (0);
}

t_map	*get_map_as_list(char *argv)
{
	t_map	*map;
	char	*tmp;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	while (!map || tmp)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (!map)
			map = ft_lstnew(tmp);
		else
			ft_lstadd_back(&map, ft_lstnew(tmp));
	}
	free(tmp);
	close(fd);
	return (map);
}

char	**get_map_as_tab(t_map *lstmap)
{
	t_map	*tmp;
	int		i;
	char	**map;

	tmp = lstmap;
	i = 0;
	if (!format_checker(lstmap) || !edge_checker(lstmap))
		return (NULL);
	map = malloc(sizeof(char *) * (ft_lstsize(lstmap) + 1));
	if (!map)
	{
		ft_lstclear(&tmp, free);
		return (NULL);
	}
	while (lstmap)
	{
		map[i++] = ft_strdup(lstmap->content);
		lstmap = lstmap->next;
	}
	map[i] = 0;
	ft_lstclear(&tmp, free);
	return (map);
}

char	**get_map(char *argv, t_game *game)
{
	char	**map;
	t_map	*lstmap;

	lstmap = (get_map_as_list(argv));
	if (!lstmap)
	{
		free(game);
		ft_perror("Invalid name of map", NULL);
	}
	map = get_map_as_tab(lstmap);
	if (!map)
	{
		ft_putendl_fd("Error\nMap format error", 1);
		return (NULL);
	}
	if (!verif_features(map))
	{
		free(game);
		ft_perror("Wrong map config", map);
	}
	get_player_coos(map, game);
	manage_floodfill(map, argv, game->player_x, game->player_y);
	return (map);
}
