/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:53 by maregnie          #+#    #+#             */
/*   Updated: 2024/11/06 15:56:31 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	newstr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	free(s1);
	return (newstr);
}

char	*ft_strchr(char *s, char c)
{
	int		i;
	int		len;
	char	*str;
	char	letter;

	letter = c;
	str = (char *)s;
	i = 0;
	len = ft_strlen(str);
	while (i < len + 1)
	{
		if (str[i] == letter)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*get_lines(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(i + 1 + (buffer[i] == '\n'), 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
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
	str = ft_calloc(ft_strlen(allstrs) - i + 1, 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (allstrs[i])
		str[j++] = allstrs[i++];
	free(allstrs);
	return (str);
}
