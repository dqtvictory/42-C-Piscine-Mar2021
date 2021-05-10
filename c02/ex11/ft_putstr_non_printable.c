/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:37:06 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:33:09 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_hex(unsigned int n)
{
	char 	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16);
	write(1, base + n % 16, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;

	while (*str)
	{
		c = (unsigned char)(*str);
		if (' ' <= c && c <= '~')
			write(1, &c, 1);
		else
		{
			write(1, "\\", 1);
			if (c < 16)
				write(1, "0", 1);
			put_hex(c);
		}
		str++;
	}
}
