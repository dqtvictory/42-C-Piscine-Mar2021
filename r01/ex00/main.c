/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:10:14 by esivre            #+#    #+#             */
/*   Updated: 2021/03/21 17:18:59 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush.h"

void	message_error(void)
{
	write(1, "Error\n", 6);
}

void	print_buffer(int *buffer, int size)
{
	int		i;
	int		size_line;
	char	a;

	i = 1;
	while (i < size)
	{
		if (size / i == i && size % i == 0)
			size_line = i;
		i++;
	}
	i = 0;
	while (i < size)
	{
		a = '0' + buffer[i];
		write(1, &a, 1);
		(((i + 1) % size_line == 0) ? write(1, "\n", 1) : write(1, " ", 1));
		i++;
	}
}

int		general_check(int argc, char *argv_1, int *size, int **input)
{
	if (argc != 2)
	{
		message_error();
		return (0);
	}
	if (!(*size = check_input(argv_1)))
	{
		message_error();
		return (0);
	}
	if (!(*input = atoi_tab(argv_1, *size)))
	{
		message_error();
		return (0);
	}
	else
		return (1);
}

int		main(int argc, char **argv)
{
	int size;
	int *input;
	int *buffer;

	input = NULL;
	if (general_check(argc, argv[1], &size, &input) == 0)
		return (0);
	buffer = init_buffer(size * size / 16);
	if (solve(0, size / 4, buffer, input) == 1)
		print_buffer(buffer, size * size / 16);
	else
		message_error();
	free(input);
	free(buffer);
	return (0);
}
