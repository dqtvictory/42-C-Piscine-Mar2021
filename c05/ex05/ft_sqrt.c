/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:28:44 by qdam              #+#    #+#             */
/*   Updated: 2021/03/18 13:46:07 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	unsigned int	n;

	if (nb <= 0)
		return (0);
	n = 1;
	while (n * n < (unsigned int)nb)
		n++;
	if (n * n == (unsigned int)nb)
		return (n);
	else
		return (0);
}
