/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:27:52 by qdam              #+#    #+#             */
/*   Updated: 2021/03/24 17:05:47 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cmp(int a, int b, int (*f)(int, int))
{
	int	c;

	c = (*f)(a, b);
	if (c < 0)
		return (-1);
	else if (c == 0)
		return (0);
	else
		return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 0;
	while (i < length - 1)
	{
		if (!order && cmp(tab[i], tab[i + 1], f))
			order = cmp(tab[i], tab[i + 1], f);
		else if (order && order == -1 * cmp(tab[i], tab[i + 1], f))
			return (0);
		i++;
	}
	return (1);
}
