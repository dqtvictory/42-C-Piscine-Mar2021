/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:11:50 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 15:53:30 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush2.h"

int		error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int		dict_error(void)
{
	write(STDERR_FILENO, "Dict Error\n", 11);
	return (1);
}

int		is_white(char c)
{
	return (c == '\t' || c == '\n'
	|| c == '\v' || c == '\f'
	|| c == '\r' || c == ' ');
}

int		check_num(char **num)
{
	int	i;
	int	sign;

	while (is_white(*(*num)))
		(*num)++;
	sign = 1;
	while (*(*num) == '+' || *(*num) == '-')
	{
		if (*(*num) == '-')
			sign *= -1;
		(*num)++;
	}
	if (sign == -1)
		return (0);
	while (*(*num) == '0')
		(*num)++;
	i = 0;
	while ((*num)[i])
	{
		if ((*num)[i] < '0' || (*num)[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*fname;
	char	*num;
	t_dict	*dict;

	if (argc > 3 || argc == 1)
		return (error());
	num = (argc == 2) ? argv[1] : argv[2];
	fname = (argc == 2) ? "numbers.dict" : argv[1];
	if (!(dict = malloc(sizeof(t_dict))))
		return (0);
	if (!check_num(&num))
		return (error());
	if (!check_dict(fname, dict))
		return (dict_error());
	if (!read_num(num, dict))
		return (dict_error());
	free_dict(dict);
	return (0);
}
