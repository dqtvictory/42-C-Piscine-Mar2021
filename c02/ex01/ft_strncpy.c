/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:33:40 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:19:01 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int 			fin;
	unsigned int	i;

	fin = 0;
	i = 0;
	while (i < n)
	{
		if (!fin)
		{
			dest[i] = src[i];
			if (src[i] == 0)
				fin = 1;
		}
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}
