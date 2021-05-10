/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:08:04 by qdam              #+#    #+#             */
/*   Updated: 2021/03/23 07:58:14 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	copy_str(char *src, char *dest, int len_s)
{
	int	i;

	i = 0;
	while (i < len_s)
	{
		dest[i] = src[i];
		i++;
	}
}

int		len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	join(char **strs, int size, char *big_str, char *sep)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	while (j < size)
	{
		l = len(strs[j]);
		copy_str(strs[j], big_str + i, l);
		if (j < size - 1)
			copy_str(sep, big_str + i + l, len(sep));
		i += l + len(sep);
		j++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*big_str;
	int		i;
	int		big_len;

	big_len = 0;
	if (size > 0)
	{
		i = 0;
		while (i < size)
		{
			big_len += len(strs[i]);
			i++;
		}
		big_len += len(sep) * (size - 1);
	}
	if (!(big_str = malloc(sizeof(char) * (big_len + 1))))
		return (0);
	big_str[big_len] = 0;
	join(strs, size, big_str, sep);
	return (big_str);
}
