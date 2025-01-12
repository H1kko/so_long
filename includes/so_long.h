/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:29:10 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/10 14:00:36 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <fcntl.h>

void	is_map_valid(t_map *map);
void	ft_perror(char *str);
char	*get_next_line(int fd);
t_map	*get_map(int fd);

#endif
