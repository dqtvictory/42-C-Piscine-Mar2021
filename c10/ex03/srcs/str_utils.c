/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:06:37 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 15:36:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*ft_strdup(char *src, long size)
{
	char	*dup;
	int		i;

	if (!(dup = malloc(size + 1)))
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		dest[i] = src[i];
}

int		is_printable(char c)
{
	return (' ' <= c && c <= '~');
}
