/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:13:33 by qdam              #+#    #+#             */
/*   Updated: 2021/03/15 16:13:43 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int		n;
	unsigned int		ten;
	unsigned int		i;
	char				c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	n = (unsigned int)nb;
	ten = 1;
	while (n / ten >= 10)
		ten *= 10;
	while (ten > 0)
	{
		i = n / ten;
		c = '0' + i;
		write(1, &c, 1);
		n = n - ten * i;
		ten /= 10;
	}
}
