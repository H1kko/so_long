/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:18:57 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/12 14:44:52 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void is_name_valid (char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' 
		|| argv[i - 4] != '.')
		ft_perror("Invalid name of map", NULL);
}
#include <stdio.h>
int	main (int argc, char **argv)
{
	char	**map;
	int i = 0;
	
	if (argc != 2)
		return (0);
	is_name_valid(argv[1]);
	map = get_map(argv[1]);
	//========print map=========//
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
	//========print map=========//
	get_player_coos(map);
	ft_free(map);
}