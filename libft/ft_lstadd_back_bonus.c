/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:11:58 by maregnie          #+#    #+#             */
/*   Updated: 2025/01/09 14:09:44 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*last;

	last = NULL;
	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			last = ft_lstlast((*lst));
			last->next = new;
		}
	}
}
