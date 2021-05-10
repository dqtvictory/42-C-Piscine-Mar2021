/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:51:41 by qdam              #+#    #+#             */
/*   Updated: 2021/03/17 08:56:49 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	(void)argc;
	write(1, argv[0], len(argv[0]));
	write(1, "\n", 1);
}
