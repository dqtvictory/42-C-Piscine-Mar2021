/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:32:10 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 17:01:34 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush2.h"

int		all_zeros(char *num, int sz)
{
	int		i;

	i = 0;
	while (num[i] && i < sz)
	{
		if (num[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int		check_len(char *num, t_dict *dict)
{
	return (len(num) <= (dict->level * 3));
}

void	print_num(int n, t_dict *dict)
{
	if (n >= 100)
	{
		print_num(n / 100, dict);
		write(1, dict->hundred, len(dict->hundred));
		write(1, " ", 1);
		print_num(n - ((n / 100) * 100), dict);
	}
	else if (n >= 20)
	{
		write(1, (dict->tens)[n / 10], len((dict->tens)[n / 10]));
		if (n % 10 == 0)
			write(1, " ", 1);
		else
			write(1, "-", 1);
		print_num(n - ((n / 10) * 10), dict);
	}
	else if (n > 0)
	{
		write(1, (dict->smalls)[n], len((dict->smalls)[n]));
		write(1, " ", 1);
	}
}

void	print_group(char *num, int sz, char *g_name, t_dict *dict)
{
	char	str[sz + 1];
	int		n;

	ft_strncpy(str, num, sz);
	if (!sz || all_zeros(num, sz))
		return ;
	n = ft_atoi(str);
	print_num(n, dict);
	write(1, g_name, len(g_name));
	if (g_name[0] != 0)
		write(1, " ", 1);
}

int		read_num(char *num, t_dict *dict)
{
	int	len_first;
	int	n_groups;
	int	i;

	if (all_zeros(num, len(num)))
	{
		write(1, (dict->smalls)[0], len((dict->smalls)[0]));
		write(1, "\n", 1);
		return (1);
	}
	if (!check_len(num, dict))
		return (0);
	len_first = len(num) % 3;
	n_groups = len(num) / 3;
	print_group(num, len_first, (dict->bigs)[n_groups], dict);
	num += len_first;
	i = n_groups - 1;
	while (i >= 0)
	{
		print_group(num, 3, (dict->bigs)[i], dict);
		i--;
		num += 3;
	}
	write(1, "\n", 1);
	return (1);
}
