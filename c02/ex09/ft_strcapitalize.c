/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:35:58 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:28:09 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		in_range(char n, char low, char high)
{
	return (low <= n && n <= high);
}

int		is_alphanum(char c)
{
	return (in_range(c, 'a', 'z')
		|| in_range(c, 'A', 'Z')
		|| in_range(c, '0', '9'));
}

void	to_upper(char *c)
{
	int	offset;

	offset = 'A' - 'a';
	if (in_range(*c, 'a', 'z'))
		*c += offset;
}

void	to_lower(char *c)
{
	int	offset;

	offset = 'a' - 'A';
	if (in_range(*c, 'A', 'Z'))
		*c += offset;
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_word;;

	i = 0;
	is_word = 0;
	while (str[i])
	{
		if (!is_alphanum(str[i]))
			is_word = 0;
		else if (!is_word)
		{
			to_upper(str + i);
			is_word = 1;
		}
		else
			to_lower(str + i);
		i++;
	}
	return (str);
}
