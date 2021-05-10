/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:16:40 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:05:59 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && tab[j] < tab[j - 1])
		{
			swap_int(tab + j, tab + j - 1);
			j--;
		}
		i++;
	}
}
