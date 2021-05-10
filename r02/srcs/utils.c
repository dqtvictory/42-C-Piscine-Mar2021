/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:05:00 by qdam              #+#    #+#             */
/*   Updated: 2021/03/28 15:58:46 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush2.h"

void	ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	dest[i] = 0;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 != *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		len_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (is_digit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
