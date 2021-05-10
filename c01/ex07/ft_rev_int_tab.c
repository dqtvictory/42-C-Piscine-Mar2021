/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:16:29 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:05:35 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;

	i = 0;	
	while (i < size / 2)
	{
		swap_int(tab + i, tab + size - 1 - i);
		i++;
	}
}
