/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:57:51 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 15:36:41 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <libgen.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

# define BF_SZ 16

typedef struct	s_buf_reader
{
	char	buf[BF_SZ];
	char	last[BF_SZ];
	long	br;
	long	total;
	int		star;
	int		opt_c;
}				t_buf_reader;

void			init_reader(t_buf_reader *reader);
int				read_stdin(t_buf_reader *reader);
int				read_file(int fd, t_buf_reader *reader);
void			print_total(t_buf_reader *r);

char			*ft_strdup(char *src, long size);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_strncpy(char *dest, char *src, int n);
int				is_printable(char c);

void			write_hex_offset(long offset, int len);
void			write_hex_ch(char *str, long to_write, int opt_c);
void			write_dec_ch(char *buffer, long to_write);
void			display(t_buf_reader *r, long offset, long br);

#endif
