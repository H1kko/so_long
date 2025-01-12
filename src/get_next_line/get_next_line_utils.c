/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:53 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/09 16:23:11 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_lines(char *buffer)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(i + 1 + (buffer[i] == '\n'), 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		str[j++] = '\n';
	return (str);
}

char	*clean_this_line(char *allstrs)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (allstrs[i] && allstrs[i] != '\n')
		i++;
	if (!allstrs[i])
	{
		free(allstrs);
		return (NULL);
	}
	i++;
	str = ft_calloc(ft_strlen(&allstrs[i]) + 1, 1);
	if (!str)
		return (NULL);
	j = 0;
	while (allstrs[i])
		str[j++] = allstrs[i++];
	free(allstrs);
	return (str);
}
