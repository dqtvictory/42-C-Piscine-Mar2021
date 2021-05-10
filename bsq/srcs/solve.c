/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:17:14 by esivre            #+#    #+#             */
/*   Updated: 2021/04/01 08:36:46 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	upgrade(t_square *best, t_square try)
{
	best->row = try.row;
	best->col = try.col;
	best->size = try.size;
}

void	square_init(t_square *sq)
{
	sq->row = 0;
	sq->col = 0;
	sq->size = 1;
}

void	solve(t_map *map)
{
	int			i;
	int			j;
	t_square	try_sq;

	j = -1;
	square_init(&try_sq);
	while (try_sq.row < map->nbrows)
	{
		i = check_square(try_sq, map, &j);
		if (i == -1 && try_sq.col + try_sq.size <= map->nbcols)
		{
			upgrade(&map->best, try_sq);
			try_sq.size++;
		}
		else if (i == -1
		&& (try_sq.size == map->nbcols || try_sq.size == map->nbrows))
			break ;
		else
			try_sq.col = i + 1;
		if (!check_outofmap(&try_sq, map))
			break ;
	}
	print_map(map);
}
