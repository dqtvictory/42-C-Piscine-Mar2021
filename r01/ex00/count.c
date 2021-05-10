/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:59:23 by esivre            #+#    #+#             */
/*   Updated: 2021/03/21 15:20:20 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	rev_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

int		n_views(int *line, int len)
{
	int	i;
	int max;
	int view;

	i = 0;
	max = 0;
	view = 0;
	while (i < len)
	{
		if (line[i] > max)
		{
			max = line[i];
			view++;
		}
		i++;
	}
	return (view);
}
