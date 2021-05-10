/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:14:47 by qdam              #+#    #+#             */
/*   Updated: 2021/03/16 07:44:10 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white(char c)
{
	return (c == '\t' || c == '\n'
	|| c == '\v' || c == '\f'
	|| c == '\r' || c == ' ');
}

int	is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	num;
	int	digit;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] && is_white(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_numeric(str[i]))
	{
		digit = str[i] - '0';
		num = num * 10 + digit;
		i++;
	}
	return (num * sign);
}
