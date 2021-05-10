/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:35:06 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:28:37 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_range(char n, char low, char high)
{
	return (low <= n && n <= high);
}

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!in_range(*str, ' ', '~'))
			return 0;
		str++;
	}
	return 1;
}
