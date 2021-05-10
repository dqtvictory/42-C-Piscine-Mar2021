/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:27:12 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 15:39:50 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

long	check_args(int ac, char **av)
{
	char	*nbr;
	long	offset;

	if (ac == 1)
		return (0);
	if (cmp(av[1], "-c", 2))
		return (0);
	if (len(av[1]) > 2)
		nbr = av[1] + 2;
	else
		nbr = av[2];
	offset = ft_atoi(nbr);
	if (offset < 0)
	{
		put_bad_offset(basename(av[0]), nbr);
		return (0);
	}
	return (offset);
}

void	begin_read(int ac, char **av, long offset, char *pname)
{
	int	i;
	int	fd;
	int	nl;

	i = 0;
	nl = 0;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
			put_err(basename(pname), av[i], strerror(errno));
		else
		{
			if (!nl)
				nl = 1;
			else
				write(1, "\n", 1);
			put_header(av[i]);
			if (read_one(fd, offset) < 0)
				put_err(basename(pname), av[i], strerror(errno));
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	long	offset;

	offset = check_args(ac, av);
	if (!offset)
		return (1);
	i = len(av[1]) == 2 ? 3 : 2;
	if (i == ac)
	{
		if (read_one(STDIN_FILENO, offset) < 0)
			put_err(basename(av[0]), 0, strerror(errno));
		return (0);
	}
	else if (i == ac - 1)
	{
		fd = open(av[ac - 1], O_RDONLY);
		if (fd < 0 || read_one(fd, offset) < 0)
			put_err(basename(av[0]), av[ac - 1], strerror(errno));
	}
	else
		begin_read(ac - i, av + i, offset, av[0]);
	return (0);
}
