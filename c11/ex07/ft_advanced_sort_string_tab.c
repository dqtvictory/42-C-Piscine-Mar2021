/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 07:59:26 by qdam              #+#    #+#             */
/*   Updated: 2021/03/24 08:09:07 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_ptr(char **p1, char **p2)
{
	char	*temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	count;

	count = 0;
	while (tab[count])
		count++;
	i = 1;
	while (i < count)
	{
		j = i;
		while (j > 0 && (*cmp)(tab[j], tab[j - 1]) < 0)
		{
			swap_ptr(tab + j, tab + j - 1);
			j--;
		}
		i++;
	}
}
