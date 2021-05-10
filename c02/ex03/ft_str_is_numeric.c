/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:34:26 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:29:32 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_range(char n, char low, char high)
{
	return (low <= n && n <= high);
}

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!in_range(*str, '0', '9'))
			return (0);
		str++;
	}
	return (1);
}
