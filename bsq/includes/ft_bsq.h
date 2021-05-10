/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:05:14 by qdam              #+#    #+#             */
/*   Updated: 2021/04/01 10:52:32 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdio.h>
# include <unistd.h>
# include <libgen.h>
# include <fcntl.h>
# include <stdlib.h>

# define MAP_ERROR "map error\n"
# define BUFF_SZ 65535
# define IMPOSSIBLE 65535

typedef struct s_str_list	t_str_list;
typedef struct s_obs		t_obs;
typedef struct s_square		t_square;
typedef struct s_map		t_map;
typedef struct s_queue		t_queue;

void						init_list(t_str_list *list);
void						init_map(t_map *map);
t_map						*create_map(t_str_list *list);
void						print_map(t_map *map);

t_map						*free_list(t_str_list *list);
t_map						*free_array(char **array);
t_map						*free_map(t_map *map);

char						**ft_split(char *str, char *charset);
long						ft_atoi(char *str, long len);
long						ft_strlen(char *str);
void						ft_strncpy(char *dest, char *src, long n);
char						*ft_strndup(char *src, long n);
void						solve(t_map *map);
int							check_obs(t_square sq, t_obs obs);
int							check_square(t_square try_sq, t_map *map, int *j);
int							check_outofmap(t_square *try_sq, t_map *map);

long						no_double(char *str);
long						count_char(char c, char *str);
long						count_strs(char **strs);
long						index_of(char c, char *str);
long						only_contains(char *charset, char *str);

struct						s_str_list
{
	char		*str;
	long		len;
	t_str_list	*next;
};

struct						s_obs
{
	long	row;
	long	col;
};

struct						s_square
{
	long	row;
	long	col;
	long	size;
};

struct						s_map
{
	char		empty;
	char		full;
	char		obs;
	long		nbrows;
	long		nbcols;
	long		nbobs;
	t_square	best;
	t_obs		*obs_map;
};

struct						s_queue
{
	long		row;
	long		col;
	t_queue		*next;
};

#endif
