/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:44:33 by esivre            #+#    #+#             */
/*   Updated: 2021/04/01 08:45:09 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	map_error(void)
{
	write(STDERR_FILENO, MAP_ERROR, ft_strlen(MAP_ERROR));
}

t_map	*try_read(int fd)
{
	long		br;
	char		buffer[BUFF_SZ];
	t_str_list	*list;
	t_str_list	*cur;
	t_map		*map;

	if (!(list = malloc(sizeof(t_str_list))))
		return (0);
	init_list(list);
	cur = list;
	while ((br = read(fd, buffer, BUFF_SZ)) > 0)
	{
		if (!(cur->str = malloc(sizeof(char) * br)))
			return (free_list(list));
		cur->str = ft_strndup(buffer, br);
		cur->len = (int)br;
		if (!(cur->next = malloc(sizeof(t_str_list))))
			return (free_list(list));
		init_list(cur->next);
		cur = cur->next;
	}
	map = create_map(list);
	free_list(list);
	return (map);
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	t_map	*map;

	i = (ac == 1) ? 0 : 1;
	while (i < ac)
	{
		if (i == 0)
			fd = STDIN_FILENO;
		else if ((fd = open(av[i], O_RDONLY)) < 0)
			map_error();
		if (fd >= 0 && !(map = try_read(fd)))
			map_error();
		else if (fd >= 0)
		{
			solve(map);
			free_map(map);
		}
		if (ac > 2 && i < ac - 1)
			write(1, "\n", 1);
		i++;
	}
}
