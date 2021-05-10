/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:37:09 by qdam              #+#    #+#             */
/*   Updated: 2021/03/26 16:33:47 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_all(t_buf_list *first)
{
	t_buf_list *current;

	current = first;
	while (current->size)
	{
		write(STDOUT_FILENO, current->buf, current->size);
		current = current->next;
	}
}

void	print_last(char *buf, long len, long buf_size)
{
	write(STDOUT_FILENO, buf + buf_size - len, len);
}

void	put_header(char *fn)
{
	write(1, "==> ", 4);
	write(1, fn, len(fn));
	write(1, " <==\n", 5);
}

void	display(t_buf_list *first, long offset)
{
	long		total;
	t_buf_list	*current;
	t_buf_list	*last;

	total = 0;
	current = first;
	while (current->size)
	{
		total += current->size;
		current = current->next;
	}
	if (total <= offset || offset == NO_OFFSET)
	{
		print_all(first);
		return ;
	}
	current = first;
	while (total > offset)
	{
		total -= current->size;
		last = current;
		current = current->next;
	}
	print_last(last->buf, offset - total, last->size);
	print_all(last->next);
}

void	clear_mem(t_buf_list *first)
{
	t_buf_list *current;
	t_buf_list *temp;

	current = first;
	while (current->size)
	{
		temp = current->next;
		free(current->buf);
		free(current);
		current = temp;
	}
	free(current);
}
