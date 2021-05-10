/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:35:35 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:28:20 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_upper(char c)
{
	return ('A' <= c && c <= 'Z');
}

char	*ft_strupcase(char *str)
{
	char	*s;
	int		offset;

	s = str;
	offset = 'a' - 'A';
	while (*s)
	{
		if (is_upper(*s))
			*s += offset;
		s++;
	}
	return (str);
}
