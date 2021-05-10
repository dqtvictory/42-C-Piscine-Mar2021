/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:04:43 by qdam              #+#    #+#             */
/*   Updated: 2021/03/25 11:06:10 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int		main(int ac, char **av)
{
	if (ac < 2)
		return (error(FNAME_MISSING));
	else if (ac > 2)
		return (error(TOO_MANY_ARGS));
	if (read_from(av[1]) < 0)
		return (error(CANT_READ));
	return (0);
}
