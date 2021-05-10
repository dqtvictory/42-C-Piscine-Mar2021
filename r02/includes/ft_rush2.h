/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:02:28 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 15:59:20 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH2_H
# define FT_RUSH2_H

# include <libgen.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SZ 102399

typedef struct	s_dict
{
	char	*smalls[20];
	char	*tens[10];
	char	*hundred;
	char	**bigs;
	int		level;
}				t_dict;

void			ft_strncpy(char *dest, char *src, int n);
int				ft_strcmp(char *s1, char *s2);
int				len(char *str);
int				len_line(char *line);
int				ft_atoi(char *str);
void			free_array(char **arr, int size);
int				is_printable(char *str);
int				is_digit(char c);
int				is_numeric(char *num);
int				is_power_1000(char *num);
char			**ft_split(char *str, char *charset);

int				put_small_num(t_dict *dict, int num, char *text);
int				put_hundred(t_dict *dict, char *num, char *text);
int				put_big_num(t_dict *dict, char *num, char *text);
int				put_to_dict(t_dict *dict, char **parts);
int				check_dict(char *fname, t_dict *dict);
int				count_bigs(char *buffer);
int				check_parts(char **parts);
int				parse_dict(t_dict *dict, char *buffer);
int				init_dict(t_dict *dict);
int				final_check(t_dict *dict);
int				free_dict(t_dict *dict);

int				read_num(char *num, t_dict *dict);

#endif
