/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:22:19 by qdam              #+#    #+#             */
/*   Updated: 2021/03/18 13:58:34 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *str)
{
	int	l;

	l = 0;
	while (*str++)
		l++;
	return (l);
}

int	is_white(char c)
{
	return (c == '\t' || c == '\n'
	|| c == '\v' || c == '\f'
	|| c == '\r' || c == ' ');
}

int	index_of(char *tab, char c)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	correct(char *base)
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
		if (is_white(base[i]) || base[i] == '-' || base[i] == '+')
			return (0);
		char_idx = (unsigned int)(base[i]);
		if (all_chars[char_idx]++ == 1)
			return (0);
		i++;
	}
	return (l);
}

int	atoi_base(char *str, char *base)
{
	int	n_base;
	int	sign;
	int	i;
	int	num;

	n_base = len(base);
	sign = 1;
	i = 0;
	num = 0;
	while (is_white(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && index_of(base, str[i]) > -1)
	{
		num = num * n_base + index_of(base, str[i]);
		i++;
	}
	return (num * sign);
}
