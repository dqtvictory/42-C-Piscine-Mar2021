/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:38:45 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 15:39:33 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	put_err(char *pname, char *fname, char *msg)
{
	write(STDERR_FILENO, pname, ft_strlen(pname));
	write(STDERR_FILENO, ": ", 2);
	if (fname)
		write(STDERR_FILENO, fname, ft_strlen(fname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}

int		all_invalid(int ac, char **av, int opt_c)
{
	int	i;
	int	fd;

	i = opt_c ? 2 : 1;
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) > 0)
		{
			close(fd);
			return (0);
		}
		i++;
	}
	return (1);
}

int		print_invalid_files(int ac, char **av, int opt_c)
{
	int	i;
	int	fd;

	i = opt_c ? 2 : 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		put_err(basename(av[0]), av[i], strerror(errno));
		i++;
	}
	close(fd);
	put_err(basename(av[0]), av[i - 1], strerror(errno));
	return (0);
}

void	begin_read(int ac, char **av, t_buf_reader *r)
{
	int	i;
	int	fd;

	i = r->opt_c ? 2 : 1;
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0
		|| read_file(fd, r) < 0)
			put_err(basename(av[0]), av[i], strerror(errno));
		if (fd > 0)
			close(fd);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_buf_reader	r;

	init_reader(&r);
	r.opt_c = (ac == 1 || ft_strncmp(av[1], "-C", 3)) ? 0 : 1;
	if (ac == 1 || (ac == 2 && r.opt_c))
	{
		if (read_stdin(&r) < 0)
			put_err(basename(av[0]), 0, strerror(errno));
	}
	else if (all_invalid(ac, av, r.opt_c))
		return (print_invalid_files(ac, av, r.opt_c));
	else
		begin_read(ac, av, &r);
	print_total(&r);
	return (0);
}
