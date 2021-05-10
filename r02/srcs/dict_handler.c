/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:09:03 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 15:58:01 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush2.h"

int		count_bigs(char *buffer)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] == '1')
		{
			j = 0;
			while (buffer[i + 2 + j] == '0')
				j++;
			if (j >= 3)
				count++;
		}
		i++;
	}
	return (count);
}

int		check_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		if (is_numeric(parts[i]) && !is_printable(parts[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		parse_dict(t_dict *dict, char *buffer)
{
	int		n_bigs;
	int		i;
	char	**parts;

	n_bigs = count_bigs(buffer);
	if (!(dict->bigs = malloc(sizeof(char *) * (n_bigs + 1))))
		return (0);
	if (!((dict->bigs)[0] = malloc(sizeof(char))))
		return (0);
	(dict->bigs)[0][0] = 0;
	i = 1;
	while (i < n_bigs + 1)
		(dict->bigs)[i++] = 0;
	dict->level = n_bigs + 1;
	parts = ft_split(buffer, " \t\r\n:");
	if (!check_parts(parts) || !put_to_dict(dict, parts))
		return (0);
	i = 0;
	while (parts[i])
		i++;
	free_array(parts, i + 1);
	free(parts);
	return (1);
}

int		init_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		(dict->smalls)[i] = 0;
		(dict->tens)[i] = 0;
		i++;
	}
	while (i < 20)
	{
		(dict->smalls)[i] = 0;
		i++;
	}
	if (!((dict->tens)[0] = malloc(sizeof(char)))
	|| !((dict->tens)[1] = malloc(sizeof(char))))
		return (0);
	(dict->tens)[0][0] = 0;
	(dict->tens)[1][0] = 0;
	dict->hundred = 0;
	dict->bigs = 0;
	dict->level = 0;
	return (1);
}
