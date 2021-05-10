/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:39:02 by qdam              #+#    #+#             */
/*   Updated: 2021/03/26 14:29:52 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	add(int a, int b)
{
	ft_putnbr(a + b);
	ft_putch('\n');
}

void	minus(int a, int b)
{
	ft_putnbr(a - b);
	ft_putch('\n');
}

void	mul(int a, int b)
{
	ft_putnbr(a * b);
	ft_putch('\n');
}

void	div(int a, int b)
{
	if (!b)
		ft_putstr(DIV_0);
	else
		ft_putnbr(a / b);
	ft_putch('\n');
}

void	mod(int a, int b)
{
	if (!b)
		ft_putstr(MOD_0);
	else
		ft_putnbr(a % b);
	ft_putch('\n');
}
