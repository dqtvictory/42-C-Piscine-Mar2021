/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 07:11:02 by esivre            #+#    #+#             */
/*   Updated: 2021/03/21 17:03:11 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

int		*atoi_tab(char *argv_1, int size)
{
	int i;
	int j;
	int res;
	int *input;

	input = malloc(sizeof(int) * size);
	i = 0;
	j = 0;
	res = 0;
	while (argv_1[i])
	{
		if (argv_1[i] >= '0' && argv_1[i] <= '9')
			res = res * 10 + argv_1[i] - '0';
		else
		{
			input[j++] = res;
			res = 0;
			if (input[j - 1] > size / 4)
				return (0);
		}
		i++;
	}
	input[j] = res;
	return (input);
}

int		check_input(char *argv_1)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (argv_1[i])
	{
		if (argv_1[i++] == ' ')
			size += 1;
		else if (argv_1[i - 1] < '0' || argv_1[i - 1] > '9')
			return (0);
	}
	size += 1;
	if (size % 4 != 0 || size > 28)
		return (0);
	return (size);
}

int		*init_buffer(int size)
{
	int i;
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
		buffer[i++] = 0;
	return (buffer);
}
