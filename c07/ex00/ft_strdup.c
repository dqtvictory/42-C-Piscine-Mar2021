/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:28:37 by qdam              #+#    #+#             */
/*   Updated: 2021/03/18 10:47:02 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		len_s;

	len_s = len(src);
	if (!(dup = malloc(len_s + 1)))
		return (0);
	i = 0;
	while (i <= len_s)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
