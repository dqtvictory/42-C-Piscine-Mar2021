/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:34:10 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:29:24 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_range(char n, char low, char high)
{
	return (low <= n && n <= high);
}

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!in_range(*str, 'a', 'z') && !in_range(*str, 'A', 'Z'))
			return (0);
		str++;
	}
	return (1);
}
