/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:41:54 by qdam              #+#    #+#             */
/*   Updated: 2021/03/18 10:49:43 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max || !(range = malloc(sizeof(int) * (max - min))))
		return (0);
	i = 0;
	while (i < max - min)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
