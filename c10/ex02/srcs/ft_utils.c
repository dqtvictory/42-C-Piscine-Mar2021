/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:05:07 by qdam              #+#    #+#             */
/*   Updated: 2021/03/26 16:10:49 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	write(fd, str, len(str));
}

long	ft_atoi(char *str)
{
	int		i;
	long	num;
	long	digit;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		digit = str[i] - '0';
		num = num * 10 + digit;
		i++;
	}
	return (num);
}

int		cmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (*s1 && i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

void	put_bad_offset(char *pname, char *offset)
{
	ft_putstr(STDERR_FILENO, pname);
	ft_putstr(STDERR_FILENO, ": illegal offset -- ");
	ft_putstr(STDERR_FILENO, offset);
	ft_putstr(STDERR_FILENO, "\n");
}
