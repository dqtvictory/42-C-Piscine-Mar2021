/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 07:43:22 by qdam              #+#    #+#             */
/*   Updated: 2021/03/24 07:47:50 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_ptr(char **p1, char **p2)
{
	char	*temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int		cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
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
		while (j > 0 && cmp(tab[j], tab[j - 1]) < 0)
		{
			swap_ptr(tab + j, tab + j - 1);
			j--;
		}
		i++;
	}
}
