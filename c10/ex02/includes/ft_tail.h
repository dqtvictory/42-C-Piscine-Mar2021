/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:27:29 by qdam              #+#    #+#             */
/*   Updated: 2021/03/29 15:08:31 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <libgen.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

# define BF_SZ 4096
# define NO_OFFSET -1

typedef	struct	s_buf_list
{
	char				*buf;
	long				size;
	struct s_buf_list	*next;
}				t_buf_list;

int				len(char *str);
void			ft_putstr(int fd, char *str);
long			ft_atoi(char *str);
int				cmp(char *s1, char *s2, int n);
void			put_bad_offset(char *pname, char *offset);

char			*ft_strdup(char *src, long size);
void			put_err(char *pname, char *fname, char *msg);
int				read_one(int fd, long offset);

void			init_list_elem(t_buf_list *elem);
void			put_header(char *fn);
void			display(t_buf_list *first, long offset);
void			clear_mem(t_buf_list *first);

#endif
