/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:08:20 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 15:58:16 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush2.h"

int		put_small_num(t_dict *dict, int num, char *text)
{
	int		l;

	l = len(text);
	if (num < 20)
	{
		if ((dict->smalls)[num]
		|| !((dict->smalls)[num] = malloc(sizeof(char) * (l + 1))))
			return (0);
		ft_strncpy((dict->smalls)[num], text, l);
	}
	else if (!((dict->tens)[num / 10]))
	{
		if (!((dict->tens)[num / 10] = malloc(sizeof(char) * (l + 1))))
			return (0);
		ft_strncpy((dict->tens)[num / 10], text, l);
	}
	return (1);
}

int		put_hundred(t_dict *dict, char *num, char *text)
{
	int	l;

	if (ft_strcmp(num, "100"))
		return (0);
	l = len(text);
	if (dict->hundred
	|| !(dict->hundred = malloc(sizeof(char) * (l + 1))))
		return (0);
	ft_strncpy(dict->hundred, text, l);
	return (1);
}

int		put_big_num(t_dict *dict, char *num, char *text)
{
	int		l;

	l = len(text);
	if (!is_power_1000(num))
		return (1);
	if ((dict->bigs)[(len(num) - 1) / 3]
	|| !((dict->bigs)[(len(num) - 1) / 3] = malloc(sizeof(char) * (l + 1))))
		return (0);
	ft_strncpy((dict->bigs)[(len(num) - 1) / 3], text, l);
	return (1);
}

int		put_to_dict(t_dict *dict, char **parts)
{
	int	i;
	int	num;

	i = 0;
	while (parts[i])
	{
		if (is_numeric(parts[i]) && len(parts[i]) < 3)
		{
			num = ft_atoi(parts[i]);
			if (!put_small_num(dict, num, parts[i + 1]))
				return (0);
		}
		else if (is_numeric(parts[i]) && len(parts[i]) == 3
		&& !put_hundred(dict, parts[i], parts[i + 1]))
			return (0);
		else if (is_numeric(parts[i])
		&& !put_big_num(dict, parts[i], parts[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		check_dict(char *fname, t_dict *dict)
{
	char	buffer[BUFF_SZ + 1];
	int		fd;

	if (!init_dict(dict))
		return (free_dict(dict));
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (free_dict(dict));
	buffer[read(fd, buffer, BUFF_SZ)] = 0;
	close(fd);
	if (!parse_dict(dict, buffer))
		return (free_dict(dict));
	if (!final_check(dict))
		return (free_dict(dict));
	return (1);
}
