/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:06:57 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 11:10:01 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush2.h"

void	free_array(char **arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i])
			free(arr[i]);
}

int		is_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str > '~')
			return (0);
		str++;
	}
	return (1);
}

int		is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int		is_numeric(char *num)
{
	while (*num)
	{
		if (!is_digit(*num))
			return (0);
		num++;
	}
	return (1);
}

int		is_power_1000(char *num)
{
	int	n_zeros;

	n_zeros = 0;
	if (num++[0] != '1')
		return (0);
	while (*num)
	{
		if (*num != '0')
			return (0);
		n_zeros++;
		num++;
	}
	return (n_zeros % 3 == 0);
}
