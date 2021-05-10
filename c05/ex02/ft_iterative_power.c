/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:50:08 by qdam              #+#    #+#             */
/*   Updated: 2021/03/18 09:42:50 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	p;
	int n;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	p = 1;
	n = nb;
	while (p < power)
	{
		n *= nb;
		p++;
	}
	return (n);
}
