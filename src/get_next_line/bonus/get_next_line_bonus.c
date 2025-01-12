/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:12 by maregnie          #+#    #+#             */
/*   Updated: 2024/11/06 17:44:13 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, int n)
{
	int				i;
	char			*str;

	if (!s)
		return ;
	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rvalue;

	if ((long) nmemb < 1 || (long) size < 1)
	{
		nmemb = 0;
		size = 0;
	}
	rvalue = malloc(nmemb * size);
	if (!rvalue)
		return (NULL);
	ft_bzero(rvalue, nmemb * size);
	return (rvalue);
}

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
	static char		*buffer[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc(1, 1);
		if (!buffer[fd])
			return (NULL);
	}
	buffer[fd] = stockstring(fd, buffer[fd]);
	if (!buffer[fd] || !buffer[fd][0])
		return (NULL);
	line = get_lines(buffer[fd]);
	buffer[fd] = clean_this_line(buffer[fd]);
	return (line);
}
