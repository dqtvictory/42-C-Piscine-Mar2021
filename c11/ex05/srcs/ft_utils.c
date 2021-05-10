/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:58:29 by qdam              #+#    #+#             */
/*   Updated: 2021/03/26 14:28:07 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		index_of(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_putch(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putch('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putch('0' + nbr % 10);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putch(*str++);
}
