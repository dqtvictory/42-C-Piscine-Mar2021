/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:42:07 by qdam              #+#    #+#             */
/*   Updated: 2021/03/26 14:20:16 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

# define DIV_0 "Stop : division by zero"
# define MOD_0 "Stop : modulo by zero"

void	add(int a, int b);
void	minus(int a, int b);
void	mul(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);

int		len(char *str);
int		index_of(char c, char *str);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
void	ft_putch(char c);

int		ft_atoi(char *str);

#endif
