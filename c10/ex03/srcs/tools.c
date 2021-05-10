/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:32:38 by qdam              #+#    #+#             */
/*   Updated: 2021/04/01 10:45:50 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	put_hex(long num, char *buffer)
{
	char c;

	if (num >= 16)
	{
		put_hex(num / 16, buffer - 1);
		put_hex(num % 16, buffer);
	}
	else
	{
		c = num < 10 ? num + '0' : num - 10 + 'a';
		*buffer = c;
	}
}

void	write_hex_offset(long offset, int len)
{
	char	buff_offset[len];
	int		i;

	i = 0;
	while (i < len)
	{
		buff_offset[i] = '0';
		i++;
	}
	put_hex(offset, buff_offset + len - 1);
	write(1, buff_offset, len);
}

void	write_hex_ch(char *str, long to_write, int opt_c)
{
	long	i;
	char	write_buffer[2];

	i = 0;
	while (i < 16)
	{
		if (i < to_write)
		{
			write_buffer[0] = '0';
			write_buffer[1] = '0';
			put_hex(str[i], write_buffer + 1);
			write(1, write_buffer, 2);
		}
		else
			write(1, "  ", 2);
		if (opt_c)
		{
			write(1, " ", 1);
			write(1, " ", (i % 8 == 7) ? 1 : 0);
		}
		else if (i < 15)
			write(1, " ", 1);
		i++;
	}
}

void	write_dec_ch(char *buffer, long to_write)
{
	long	i;

	write(1, "|", 1);
	i = 0;
	while (i < to_write)
	{
		if (is_printable(buffer[i]))
			write(1, buffer + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	display(t_buf_reader *r, long offset, long br)
{
	int	len_offset;

	len_offset = r->opt_c ? 8 : 7;
	if (ft_strncmp(r->buf, r->last, BF_SZ))
	{
		write_hex_offset(offset, len_offset);
		write(1, " ", 1);
		if (r->opt_c)
			write(1, " ", 1);
		write_hex_ch(r->buf, br, r->opt_c);
		if (r->opt_c)
			write_dec_ch(r->buf, br);
		write(1, "\n", 1);
		ft_strncpy(r->last, r->buf, BF_SZ);
		r->star = 0;
	}
	else if (!(r->star))
	{
		write(1, "*\n", 2);
		r->star = 1;
	}
}
