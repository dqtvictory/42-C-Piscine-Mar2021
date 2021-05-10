/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:08:14 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 15:34:33 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_total(t_buf_reader *r)
{
	long	i;
	int		len_offset;

	if (!(r->total))
		return ;
	len_offset = r->opt_c ? 8 : 7;
	i = r->total % BF_SZ;
	while (i < BF_SZ)
	{
		(r->buf)[i] = 0;
		i++;
	}
	if (r->total % 16 > 0)
		display(r, r->total - (r->total % BF_SZ), r->total % BF_SZ);
	if (r->total)
		write_hex_offset(r->total, len_offset);
	write(1, "\n", 1);
}

void	init_reader(t_buf_reader *r)
{
	int	i;

	i = -1;
	while (++i < BF_SZ)
	{
		(r->buf)[i] = 0;
		(r->last)[i] = 0;
	}
	r->br = 0;
	r->total = 0;
	r->star = 0;
}

int		check_leftover(int fd, t_buf_reader *r)
{
	long	rem;
	long	br;

	if (r->br > 0)
	{
		rem = BF_SZ - r->br;
		br = read(fd, r->buf + r->br, rem);
		r->br += br;
		r->total += br;
		if (br == rem)
			display(r, r->total - 16, BF_SZ);
		else
			return (0);
	}
	return (1);
}

int		read_stdin(t_buf_reader *r)
{
	long	rem;
	long	br;

	while (1)
	{
		rem = (r->br == BF_SZ) ? BF_SZ : BF_SZ - r->br;
		br = read(STDIN_FILENO, r->buf + BF_SZ - rem, rem);
		if (!br)
			break ;
		r->br = br;
		r->total += br;
		if (r->total % BF_SZ == 0)
			display(r, r->total - 16, BF_SZ);
	}
	if (br > 0)
		return (-1);
	return (0);
}

int		read_file(int fd, t_buf_reader *r)
{
	long	br;

	if (!check_leftover(fd, r))
		return (0);
	while ((br = read(fd, r->buf, BF_SZ)) > 0)
	{
		r->br = br;
		r->total += br;
		if (br == BF_SZ)
			display(r, r->total - 16, BF_SZ);
	}
	if (br > 0)
		return (-1);
	return (0);
}
