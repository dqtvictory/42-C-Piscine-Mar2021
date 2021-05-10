/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:22:21 by qdam              #+#    #+#             */
/*   Updated: 2021/03/22 12:07:28 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		atoi_base(char *str, char *base);
int		correct(char *base);
int		len(char *str);

int		len_nbr(int nbr, char *base)
{
	int i;
	int len_base;

	if (nbr == 0)
		return (1);
	i = 0;
	len_base = len(base);
	while (nbr)
	{
		nbr = nbr / len_base;
		i++;
	}
	return (i);
}

void	putnbr_base(unsigned int nbr, char *buffer, char *base, int n_base)
{
	char c;

	if (nbr >= (unsigned int)n_base)
	{
		putnbr_base(nbr / (unsigned int)n_base, buffer - 1, base, n_base);
		putnbr_base(nbr % (unsigned int)n_base, buffer, base, n_base);
	}
	else
	{
		c = base[nbr];
		*buffer = c;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		num;
	int		alloc_bytes;
	int		len_n;
	int		negative;

	if (!correct(base_from) || !correct(base_to))
		return (0);
	num = atoi_base(nbr, base_from);
	len_n = len_nbr(num, base_to);
	alloc_bytes = num >= 0 ? len_n : len_n + 1;
	if (!(result = malloc(alloc_bytes + 1)))
		return (0);
	negative = 0;
	if (num < 0)
	{
		num *= -1;
		*(result++) = '-';
		negative = 1;
	}
	putnbr_base((unsigned int)num, result + len_n - 1, base_to, len(base_to));
	result[len_n] = 0;
	return (result - negative);
}
