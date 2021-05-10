/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:35:07 by esivre            #+#    #+#             */
/*   Updated: 2021/03/21 15:09:46 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

void	message_error(void);

void	print_buffer(int *buffer, int size);

int		general_check(int argc, char *argv_1, int *size, int **input);

int		*init_buffer(int size);

int		solve(int c, int size, int *buffer, int *input);

int		check_input(char *arv_1);

int		*atoi_tab(char *argv_1, int size);

void	rev_tab(int *tab, int size);

int		check_up(int idx, int val, int *up);

int		check_left(int idx, int val, int *left);

int		n_views(int *line, int len);

int		check(int idx, int val);

#endif
