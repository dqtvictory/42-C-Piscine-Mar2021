/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:15:36 by qdam              #+#    #+#             */
/*   Updated: 2021/03/23 08:41:25 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_ch(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int nbr)
{
	unsigned int	n;

	if (nbr < 0)
	{
		put_ch('-');
		nbr *= -1;
	}
	n = (unsigned int)nbr;
	if (nbr >= 10)
		put_nbr(nbr / 10);
	put_ch('0' + nbr % 10);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		put_ch(str[i++]);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		put_str(par[i].str);
		put_ch('\n');
		put_nbr(par[i].size);
		put_ch('\n');
		put_str(par[i].copy);
		put_ch('\n');
		i++;
	}
}
