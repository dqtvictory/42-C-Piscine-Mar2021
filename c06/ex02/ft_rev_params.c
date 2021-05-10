/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:51:41 by qdam              #+#    #+#             */
/*   Updated: 2021/03/17 11:36:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		putstr(argv[i]);
		write(1, "\n", 1);
		i--;
	}
}
