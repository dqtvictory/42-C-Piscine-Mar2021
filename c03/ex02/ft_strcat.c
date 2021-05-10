/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:40:46 by qdam              #+#    #+#             */
/*   Updated: 2021/03/15 16:06:25 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	l;
	int	i;

	l = len(dest);
	i = 0;
	while (src[i])
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = 0;
	return (dest);
}
