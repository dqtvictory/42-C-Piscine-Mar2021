/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:11:21 by qdam              #+#    #+#             */
/*   Updated: 2021/03/16 08:28:29 by qdam             ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	l;
	unsigned int	i;

	l = (unsigned int)(len(dest));
	i = 0;
	while (src[i] && i < nb)
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = 0;
	return (dest);
}
