/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:46:32 by qdam              #+#    #+#             */
/*   Updated: 2021/04/01 08:50:32 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

long	in_square(t_square *sq, long r, long c)
{
	return (r < (sq->row + sq->size) && c < (sq->col + sq->size)
			&& r >= sq->row && c >= sq->col);
}

void	print_map(t_map *map)
{
	long	r;
	long	c;
	long	i;

	r = -1;
	i = 0;
	while (++r < map->nbrows)
	{
		c = -1;
		while (++c < map->nbcols)
		{
			if (i < map->nbobs
			&& r == (map->obs_map)[i].row
			&& c == (map->obs_map)[i].col)
			{
				write(1, &(map->obs), 1);
				i++;
			}
			else if (in_square(&(map->best), r, c))
				write(1, &(map->full), 1);
			else
				write(1, &(map->empty), 1);
		}
		write(1, "\n", 1);
	}
}
