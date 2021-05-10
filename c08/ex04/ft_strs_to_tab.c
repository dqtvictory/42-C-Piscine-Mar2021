/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:39:39 by qdam              #+#    #+#             */
/*   Updated: 2021/03/23 08:39:05 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*dup_str(char *src)
{
	char	*dup;
	int		i;
	int		len_s;

	len_s = len(src);
	if (!(dup = malloc(len_s + 1)))
		return (0);
	i = 0;
	while (i <= len_s)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

void				copy_str(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		dest[i] = src[i];
		i++;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tab;
	int			i;
	int			l;

	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	i = 0;
	while (i < ac)
	{
		l = len(av[i]);
		tab[i].size = l;
		tab[i].str = av[i];
		tab[i].copy = dup_str(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
