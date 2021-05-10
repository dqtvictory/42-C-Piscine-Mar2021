/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_killer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:08:50 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 11:51:20 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush2.h"

int		final_check(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 10 && !((dict->tens)[i]))
			return (0);
		if (!((dict->smalls)[i]))
			return (0);
		i++;
	}
	if (!(dict->hundred))
		return (0);
	if (!(dict->level))
		return (0);
	i = 0;
	while (i < dict->level)
	{
		if (!((dict->bigs)[i]))
			return (0);
		i++;
	}
	return (1);
}

int		free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	free_array((dict->smalls), 20);
	free_array((dict->tens), 10);
	if (dict->hundred)
		free(dict->hundred);
	if (dict->bigs)
	{
		free_array(dict->bigs, dict->level);
		free(dict->bigs);
	}
	return (0);
}
