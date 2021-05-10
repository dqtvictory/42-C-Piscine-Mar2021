/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:21:13 by qdam              #+#    #+#             */
/*   Updated: 2021/03/15 16:07:16 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	len_d = len(dest);
	len_s = len(src);
	if (!size || size < len_d + 1)
		return (size + len_s);
	i = 0;
	while (src[i] && i < size - 1 - len_d)
	{
		dest[i + len_d] = src[i];
		i++;
	}
	dest[i + len_d] = 0;
	return (len_d + len_s);
}
