/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:25:12 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/10 17:35:53 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	verif_features(t_map *map)
{
	int		p;
	int		c;
	int		e;
	t_map	*tmp;
	
	p = 0;
	c = 0;
	e = 0;
	tmp = map;
	while (map)
	{
		if (ft_strchr(map->content, 'P'))
			p++;
		if (ft_strchr(map->content, 'C'))
			c++;
		if (ft_strchr(map->content, 'E'))
			e++;
		map = map->next;
	}
		if (p != 1 || c < 1 || e != 1)
		{
			ft_lstclear(&tmp, free);
			ft_perror("Wrong map config");
		}
}
int format_checker(t_map *map)
{
	int	len;
	t_map		*tmp;
	int			i;

	tmp = map;
	len = ft_strlen(map->content);
	printf("%d", len);
	while (map)
	{
		i = 0;
	 	while (map && map->content[i])
	 	{
			if ((map->content[i] != '0' && map->content[i] != '1' && map->content[i] != 'P'
	 			&& map->content[i] != 'C' && map->content[i] != 'E' && map->content[i] != '\n')
				|| ft_strlen(map->content) != (size_t)len || (map->content[0] != '1' || map->content[len - 2] != '1'))
	 		{
	 			ft_lstclear(&tmp, free);
	 			ft_perror("Map format error");
	 		}
			i++;
	 	}
		map = map->next;
	}
	return (len);
}

void edge_checker(t_map *map)
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
	 		ft_perror("Map format error");
		}
	}
	i = 0;
	map = ft_lstlast(map);
	while (map->content[i] != '\n')
	{
		if (map->content[i++] != '1')
		{
			ft_lstclear(&tmp, free);
	 		ft_perror("Map format error");
		}
	}
}

void	is_map_valid(t_map *map)
{
	verif_features(map);
	format_checker(map);
	edge_checker(map);
}
