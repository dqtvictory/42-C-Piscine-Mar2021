/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:05:57 by qdam              #+#    #+#             */
/*   Updated: 2021/03/30 17:06:03 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	init_list(t_str_list *list)
{
	list->str = 0;
	list->len = 0;
	list->next = 0;
}

void	init_map(t_map *map)
{
	map->empty = 0;
	map->full = 0;
	map->obs = 0;
	map->nbrows = 0;
	map->nbcols = 0;
	map->nbobs = 0;
	(map->best).row = 0;
	(map->best).col = 0;
	(map->best).size = 1;
	map->obs_map = 0;
}
