/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:18:57 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/10 14:00:18 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void is_name_valid (char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' 
		|| argv[i - 4] != '.')
		ft_perror("Invalid name of map");
}

int	main (int argc, char **argv)
{
	int fd;
	t_map	*map;
	
	if (argc != 2)
		return (0);
	is_name_valid(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_perror("Invalid name of map");
	map = get_map(fd);
	ft_lstprint(map);
	close(fd);
	is_map_valid (map);
	ft_lstclear(&map, free);
}