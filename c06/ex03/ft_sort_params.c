/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:06:01 by qdam              #+#    #+#             */
/*   Updated: 2021/03/17 11:31:51 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	swap_ptr(char **p1, char **p2)
{
	char *temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i;
		while (j > 1 && cmp(argv[j], argv[j - 1]) < 0)
		{
			swap_ptr(argv + j, argv + j - 1);
			j--;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
