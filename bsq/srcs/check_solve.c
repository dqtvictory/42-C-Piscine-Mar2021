/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:30:16 by esivre            #+#    #+#             */
/*   Updated: 2021/04/01 08:37:19 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		check_obs(t_square sq, t_obs obs)
{
	if (obs.col < sq.col + sq.size && obs.col >= sq.col
			&& obs.row < sq.row + sq.size && obs.row >= sq.row)
		return (1);
	if (obs.row < sq.row)
		return (2);
	return (0);
}

int		check_outofmap(t_square *try_sq, t_map *map)
{
	if (try_sq->col + try_sq->size > map->nbcols)
	{
		try_sq->col = 0;
		try_sq->row++;
	}
	if (try_sq->row + try_sq->size > map->nbrows)
		return (0);
	return (1);
}

int		check_square(t_square try_sq, t_map *map, int *j)
{
	int rightcol;
	int is_obs;
	int i;

	rightcol = 0;
	is_obs = 0;
	i = *j;
	while (++i < map->nbobs)
	{
		if (check_obs(try_sq, (map->obs_map)[i]) == 1)
		{
			is_obs = 1;
			if ((map->obs_map)[i].col > rightcol)
			{
				if ((map->obs_map)[i].row == try_sq.row)
					*j = i;
				rightcol = (map->obs_map)[i].col;
			}
		}
		*j = (check_obs(try_sq, (map->obs_map)[i]) == 2) ? i + 1 : *j;
		if ((rightcol == try_sq.size + try_sq.col - 1 && is_obs == 1)
		|| (map->obs_map)[i].row > try_sq.row + try_sq.size)
			break ;
	}
	return (is_obs == 0 ? -1 : rightcol);
}
