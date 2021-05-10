/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:35:57 by qdam              #+#    #+#             */
/*   Updated: 2021/03/25 11:02:39 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int		main(int ac, char **av)
{
	char	*pname;
	char	*fname;
	int		i;

	pname = basename(av[0]);
	if (ac == 1 && read_from(0) < 0)
		put_err(pname, 0, strerror(errno));
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && len(av[i]) == 1)
			fname = 0;
		else
			fname = av[i];
		if (read_from(fname) < 0)
			put_err(pname, fname, strerror(errno));
		i++;
	}
	return (0);
}
