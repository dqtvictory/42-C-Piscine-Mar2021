/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:19:59 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:56:50 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_hex(size_t num, char *buf)
{
	char	*base;

	base = "0123456789abcdef";
	if (num >= 16)
	{
		put_hex(num / 16, buf - 1);
		put_hex(num % 16, buf);
	}
	else
		*buf = base[num];
}

void	write_hex_addr(char *addr_ch)
{
	char	buf[16];
	int 	i;

	i = 0;
	while (i < 16)
		buf[i++] = '0';
	put_hex((size_t)addr_ch, buf + 15);
	write(1, buf, 16);
	write(1, ": ", 2);
}

void	write_hex_mem(char *addr_ch, size_t to_write)
{
	char	write_buffer[2];
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (i < to_write)
		{
			write_buffer[0] = '0';
			write_buffer[1] = '0';
			put_hex(addr_ch[i], write_buffer + 1);
			write(1, write_buffer, 2);
		}
		else
			write(1, "  ", 2);
		if (i > 0 && i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	write_char_mem(char *addr_ch, size_t to_write)
{
	size_t	i;

	i = 0;
	while (i < to_write)
	{
		if (' ' <= addr_ch[i] && addr_ch[i] <= '~')
			write(1, addr_ch + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	to_write;
	char			*addr_ch;

	i = 0;
	addr_ch = (char *)addr;
	while (i < size)
	{
		to_write = (size - i > 16) ? 16 : size - i;
		write_hex_addr(addr_ch);
		write_hex_mem(addr_ch, to_write);
		write_char_mem(addr_ch, to_write);
		write(1, "\n", 1);
		i += 16;
		addr_ch += 16;
	}
	return (addr);
}

int main()
{
	char *hehe = "asklfdsjlk fsdf lksadfl sadjlkf jasldfjsadljfsadoiu fasduuf8asdfhsad sayf98ds7f97sadfsa dfsd8fdsa sa0";
	ft_print_memory(hehe, 110);
}