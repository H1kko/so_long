/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:12 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/09 16:34:18 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_all(char *buffer, char *stock)
{
	free(stock);
	free(buffer);
	return (NULL);
}

char	*stockstring(int fd, char *allstrs)
{
	char	*stock;
	int		readsize;

	readsize = 1;
	stock = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!stock || !allstrs)
		return (NULL);
	while (!ft_strchr(allstrs, '\n') && readsize > 0)
	{
		readsize = read(fd, stock, BUFFER_SIZE);
		if (readsize < 0)
			return (free_all(stock, allstrs));
		stock[readsize] = 0;
		allstrs = ft_strjoin(allstrs, stock);
		if (!allstrs)
			return (NULL);
	}
	free(stock);
	if (readsize == 0 && !allstrs[0])
	{
		free(allstrs);
		return (NULL);
	}
	return (allstrs);
}


char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	buffer = stockstring(fd, buffer);
	if (!buffer || !buffer[0])
		return (NULL);
	line = get_lines(buffer);
	buffer = clean_this_line(buffer);
	if (buffer && !buffer[0])
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
