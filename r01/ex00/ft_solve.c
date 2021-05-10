/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:00:20 by esivre            #+#    #+#             */
/*   Updated: 2021/03/21 16:40:16 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	g_size;
int	*g_buffer;
int	*g_input;

int		check_up(int idx, int val, int *up)
{
	int	i;
	int	u;
	int	len;

	len = idx / g_size + 1;
	up[len - 1] = val;
	i = 1;
	while (i < len)
	{
		u = idx - i * g_size;
		if (g_buffer[u] == val)
			return (0);
		up[len - 1 - i] = g_buffer[u];
		i++;
	}
	return (1);
}

int		check_left(int idx, int val, int *left)
{
	int	i;
	int	l;
	int	len;

	len = idx % g_size + 1;
	left[len - 1] = val;
	i = 1;
	while (i < len)
	{
		l = idx - i;
		if (g_buffer[l] == val)
			return (0);
		left[len - 1 - i] = g_buffer[l];
		i++;
	}
	return (1);
}

int		check(int idx, int val)
{
	int u[idx / g_size + 1];
	int l[idx % g_size + 1];

	if (!check_up(idx, val, u) || !check_left(idx, val, l))
		return (0);
	if (n_views(l, idx % g_size + 1) > g_input[2 * g_size + idx / g_size]
			|| n_views(u, idx / g_size + 1) > g_input[idx % g_size])
		return (0);
	if ((idx + 1) % g_size == 0)
	{
		if (n_views(l, idx % g_size + 1) != g_input[2 * g_size + idx / g_size])
			return (0);
		rev_tab(l, idx % g_size + 1);
		if (n_views(l, idx % g_size + 1) != g_input[3 * g_size + idx / g_size])
			return (0);
	}
	if (idx >= (g_size * g_size - g_size))
	{
		if (n_views(u, idx / g_size + 1) != g_input[idx % g_size])
			return (0);
		rev_tab(u, idx / g_size + 1);
		if (n_views(u, idx / g_size + 1) != g_input[g_size + idx % g_size])
			return (0);
	}
	return (1);
}

int		solve(int idx, int size, int *buffer, int *input)
{
	int	val;

	if (idx == size * size)
		return (1);
	if (idx == 0)
	{
		g_size = size;
		g_buffer = buffer;
		g_input = input;
	}
	val = 1;
	while (val <= size)
	{
		if (check(idx, val))
		{
			g_buffer[idx] = val;
			if (solve(idx + 1, size, g_buffer, g_input))
				return (1);
		}
		val++;
	}
	return (0);
}
