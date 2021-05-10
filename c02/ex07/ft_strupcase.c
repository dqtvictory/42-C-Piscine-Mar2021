/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:35:17 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:28:28 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lower(char c)
{
	return ('a' <= c && c <= 'z');
}

char	*ft_strupcase(char *str)
{
	char	*s;
	int		offset;

	s = str;
	offset = 'A' - 'a';
	while (*s)
	{
		if (is_lower(*s))
			*s += offset;
		s++;
	}
	return str;
}
