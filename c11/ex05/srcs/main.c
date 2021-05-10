/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:09:03 by qdam              #+#    #+#             */
/*   Updated: 2021/03/26 14:19:39 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "do_op.h"

int	op_error(void)
{
	ft_putstr("0\n");
	return (1);
}

int	main(int ac, char **av)
{
	char		*ops;
	void		(*funcs[5])(int, int);
	int			op;
	int			n1;
	int			n2;

	ops = "+-*/%";
	funcs[0] = add;
	funcs[1] = minus;
	funcs[2] = mul;
	funcs[3] = div;
	funcs[4] = mod;
	if (ac != 4)
		return (1);
	if (len(av[2]) != 1)
		return (op_error());
	else if (index_of(av[2][0], ops) == -1)
		return (op_error());
	op = index_of(av[2][0], ops);
	n1 = ft_atoi(av[1]);
	n2 = ft_atoi(av[3]);
	(*funcs[op])(n1, n2);
	return (0);
}
