/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:55:34 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/12 14:14:56 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*get_map_as_list(char *argv)
{
	t_map	*map;
	char	*tmp;
	int		fd;
	
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_perror("Invalid name of map", NULL);
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
	is_map_valid(lstmap);
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
	verif_features(map);
	return (map);
}

char	**get_map(char *argv)
{
	char	**map;

	map = get_map_as_tab(get_map_as_list(argv));
	return (map);
}