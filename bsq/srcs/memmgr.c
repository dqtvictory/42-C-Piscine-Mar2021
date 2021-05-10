/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:02:53 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 08:43:10 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_map	*free_list(t_str_list *list)
{
	t_str_list *cur;
	t_str_list *temp;

	cur = list;
	while (cur->str)
	{
		free(cur->str);
		temp = cur;
		cur = cur->next;
		free(temp);
	}
	return (0);
}

t_map	*free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (0);
}

t_map	*free_map(t_map *map)
{
	if (map->obs_map)
		free(map->obs_map);
	free(map);
	return (0);
}
