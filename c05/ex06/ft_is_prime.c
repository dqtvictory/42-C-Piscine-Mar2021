/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:18:20 by qdam              #+#    #+#             */
/*   Updated: 2021/03/18 09:44:19 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	n;
	unsigned int	i;

	if (nb <= 3)
		return (nb > 1);
	else if (nb == 5)
		return (1);
	else if (!(nb % 2) || !(nb % 3) || !(nb % 5))
		return (0);
	n = (unsigned int)nb;
	i = 7;
	while (i * i <= n)
	{
		if (!(n % i) || !(n % (i + 4))
		|| !(n % (i + 6)) || !(n % (i + 10))
		|| !(n % (i + 12)) || !(n % (i + 16))
		|| !(n % (i + 22)) || !(n % (i + 24)))
			return (0);
		i += 30;
	}
	return (1);
}
