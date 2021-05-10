/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:09:07 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 14:25:52 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

long	no_double(char *str)
{
	long	i;
	long	j;
	long	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	count_char(char c, char *str)
{
	long	count;

	count = 0;
	while (*str)
	{
		if (c == *str)
			count++;
		str++;
	}
	return (count);
}

long	count_strs(char **strs)
{
	long	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

long	index_of(char c, char *str)
{
	long	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

long	only_contains(char *charset, char *str)
{
	long	i;

	i = 0;
	while (str[i])
	{
		if (index_of(str[i], charset) < 0)
			return (0);
		i++;
	}
	return (1);
}
