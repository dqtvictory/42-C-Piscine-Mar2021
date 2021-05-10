/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:54:12 by qdam              #+#    #+#             */
/*   Updated: 2021/03/15 16:07:26 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (i < n && s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char			*ft_strstr(char *str, char *to_find)
{
	unsigned int	l;

	l = len(to_find);
	if (l == 0)
		return (str);
	while (*str)
	{
		if (*str == *to_find && !ft_strncmp(str, to_find, (unsigned int)l))
			return (str);
		str++;
	}
	return (0);
}
