/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:11:10 by qdam              #+#    #+#             */
/*   Updated: 2021/04/01 08:49:54 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(char *str, long len)
{
	long	i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] && i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

void	ft_strncpy(char *dest, char *src, long n)
{
	long	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strndup(char *src, long n)
{
	char	*dup;
	long	i;
	long	len_s;

	len_s = ft_strlen(src);
	if (!(dup = malloc(len_s + 1)))
		return (0);
	i = 0;
	while (i < len_s && i < (long)n)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
