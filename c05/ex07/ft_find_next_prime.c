/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:18:08 by qdam              #+#    #+#             */
/*   Updated: 2021/03/17 12:32:45 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_prime(unsigned int nb)
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

void	prep_arrays(unsigned int *tests)
{
	tests[0] = 1;
	tests[1] = 7;
	tests[2] = 11;
	tests[3] = 13;
	tests[4] = 17;
	tests[5] = 19;
	tests[6] = 23;
	tests[7] = 29;
}

int		find_next(unsigned int n, unsigned int *tests)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < 8)
		{
			if (is_prime(n + tests[i]))
				return (int)(n + tests[i]);
			i++;
		}
		n += 30;
	}
}

int		ft_find_next_prime(int nb)
{
	unsigned int	tests[8];
	unsigned int	n;

	prep_arrays(tests);
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		n = (unsigned int)nb + 1;
	else
		n = (unsigned int)nb;
	while (n % 30 != 0)
	{
		if (is_prime(n))
			return ((int)n);
		n++;
	}
	return (find_next(n, tests));
}
