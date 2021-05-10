/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:08:16 by qdam              #+#    #+#             */
/*   Updated: 2021/04/01 08:46:28 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

long	check_lines(long nl, char **lines)
{
	long	nbrows;
	long	nbcols;
	long	nbobs;
	char	*charset;

	charset = *lines + (ft_strlen(*lines) - 3);
	if (ft_strlen(*lines) < 4 || !no_double(charset))
		return (IMPOSSIBLE);
	if (!(nbrows = ft_atoi(*lines, ft_strlen(*lines) - 3))
	|| nbrows != count_strs(lines + 1) || nbrows != (nl - 1))
		return (IMPOSSIBLE);
	nbobs = 0;
	nbcols = 0;
	while (*(++lines))
	{
		if (nbcols == 0)
			nbcols = ft_strlen(*lines);
		else if (nbcols != ft_strlen(*lines))
			return (IMPOSSIBLE);
		else if (!only_contains(charset, *lines))
			return (IMPOSSIBLE);
		nbobs += count_char(charset[1], *lines);
	}
	return ((nbcols && nbrows) ? nbobs : IMPOSSIBLE);
}

long	alloc_obs(t_map *map, long nbobs)
{
	if (!(map->obs_map = malloc(sizeof(t_obs) * nbobs)))
		return (0);
	map->nbobs = nbobs;
	return (1);
}

long	put_to_map(t_map *map, char **lines)
{
	long	i;
	long	nbrows;
	long	nbcols;

	map->empty = lines[0][ft_strlen(lines[0]) - 3];
	map->obs = lines[0][ft_strlen(lines[0]) - 2];
	map->full = lines[0][ft_strlen(lines[0]) - 1];
	lines++;
	i = 0;
	nbrows = -1;
	while (lines[++nbrows])
	{
		nbcols = -1;
		while (lines[nbrows][++nbcols])
			if (lines[nbrows][nbcols] == map->obs)
			{
				(map->obs_map)[i].row = (long)nbrows;
				(map->obs_map)[i].col = (long)nbcols;
				i++;
			}
	}
	map->nbrows = nbrows;
	map->nbcols = nbcols;
	return (1);
}

t_map	*parse_map(char *buffer)
{
	t_map	*map;
	long	nl;
	long	nbobs;
	char	**lines;

	if (!(lines = ft_split(buffer, "\n")))
		return (0);
	nl = count_char('\n', buffer);
	free(buffer);
	if (!(lines[0]) || (nbobs = check_lines(nl, lines)) == IMPOSSIBLE
	|| !(map = malloc(sizeof(t_map))))
		return (free_array(lines));
	init_map(map);
	if (!alloc_obs(map, nbobs) || !put_to_map(map, lines))
	{
		free_map(map);
		return (free_array(lines));
	}
	free_array(lines);
	return (map);
}

t_map	*create_map(t_str_list *list)
{
	long		i;
	char		*buffer;
	t_str_list	*cur;
	t_map		*map;

	i = 0;
	cur = list;
	while (cur->str)
	{
		i += cur->len;
		cur = cur->next;
	}
	cur = list;
	if (!i || !(buffer = malloc(sizeof(char) * (i + 1))))
		return (0);
	buffer[i] = 0;
	i = 0;
	while (cur->str)
	{
		ft_strncpy(buffer + i, cur->str, cur->len);
		i += cur->len;
		cur = cur->next;
	}
	map = parse_map(buffer);
	return (map);
}
