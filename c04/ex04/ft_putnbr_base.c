/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:41:38 by qdam              #+#    #+#             */
/*   Updated: 2021/03/16 07:37:58 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(char *str)
{
	int	l;

	l = 0;
	while (*str++)
		l++;
	return (l);
}

int		correct(char *base)
{
	unsigned int	char_idx;
	int				l;
	int				i;
	int				all_chars[256];

	l = len(base);
	if (l == 0 || l == 1)
		return (0);
	i = 0;
	while (i < 256)
		all_chars[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		char_idx = (unsigned int)(base[i]);
		if (all_chars[char_idx]++ == 1)
			return (0);
		i++;
	}
	return (l);
}

void	print_nbr_nbase(unsigned int nbr, char *base, unsigned int n_base)
{
	char	c;

	if (nbr >= n_base)
	{
		print_nbr_nbase(nbr / n_base, base, n_base);
		print_nbr_nbase(nbr % n_base, base, n_base);
	}
	else
	{
		c = base[nbr];
		write(1, &c, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n_base;

	n_base = correct(base);
	if (!n_base)
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	print_nbr_nbase((unsigned int)nbr, base, (unsigned int)n_base);
}
