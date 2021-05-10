/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:48 by qdam              #+#    #+#             */
/*   Updated: 2021/03/18 09:45:03 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_path(int *path)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = path[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		check_placement(int row, int col, int *path)
{
	int c;
	int i;

	if (col == 0)
		return (1);
	c = col - 1;
	i = 1;
	while (c >= 0)
	{
		if (path[c] == row
		|| path[c] == row + i
		|| path[c] == row - i)
			return (0);
		i++;
		c--;
	}
	return (1);
}

void	place_queen(int col, int *path, int *n_sol)
{
	int	row;

	if (col == 10)
	{
		*n_sol += 1;
		print_path(path);
	}
	row = 0;
	while (row < 10)
	{
		if (check_placement(row, col, path))
		{
			path[col] = row;
			place_queen(col + 1, path, n_sol);
		}
		row++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int	n_sol;
	int	path[10];

	n_sol = 0;
	place_queen(0, path, &n_sol);
	return (n_sol);
}
