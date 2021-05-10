/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:47:31 by qdam              #+#    #+#             */
/*   Updated: 2021/05/10 20:01:42 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct	s_data
{
	int		n;
	char	last_num[11];
	char	num[11];
};

void	init(struct s_data *d, int n)
{
	int	i;

	d->n = n;
	i = 0;
	while (i < n)
	{
		d->last_num[n - 1 - i] = '9' - i;
		i++;
	}
}

int		str_equal(char *a, char *b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

void	print_comb(struct s_data *d, char current, int idx)
{
	char	c;

	d->num[idx] = current;
	if (idx == d->n - 1)
	{
		write(1, d->num, d->n);
		if (!str_equal(d->num, d->last_num, d->n))
			write(1, ", ", 2);
		return ;
	}	
	c = current;
	while (c <= d->last_num[idx])
	{
		print_comb(d, c + 1, idx + 1);
		c++;
	}
}

void	ft_print_combn(int n)
{
	struct s_data	d;
	char			c;

	init(&d, n);
	c = '0';
	while (c <= '9')
	{
		print_comb(&d, c, 0);
		c++;
	}
}
