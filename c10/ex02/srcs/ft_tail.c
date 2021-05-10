/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:38:32 by qdam              #+#    #+#             */
/*   Updated: 2021/03/31 15:49:03 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	init_list_elem(t_buf_list *elem)
{
	elem->buf = NULL;
	elem->next = NULL;
	elem->size = 0;
}

char	*ft_strdup(char *src, long size)
{
	char	*dup;
	int		i;

	if (!(dup = malloc(size + 1)))
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

void	put_err(char *pname, char *fname, char *msg)
{
	ft_putstr(STDERR_FILENO, pname);
	ft_putstr(STDERR_FILENO, ": ");
	if (fname)
		ft_putstr(STDERR_FILENO, fname);
	ft_putstr(STDERR_FILENO, ": ");
	ft_putstr(STDERR_FILENO, msg);
	ft_putstr(STDERR_FILENO, "\n");
}

int		read_one(int fd, long offset)
{
	char		buffer[BF_SZ];
	long		bytes_read;
	t_buf_list	*first;
	t_buf_list	*current;

	if (!(first = malloc(sizeof(t_buf_list))))
		return (-1);
	init_list_elem(first);
	current = first;
	while ((bytes_read = read(fd, buffer, BF_SZ)) > 0)
	{
		current->buf = ft_strdup(buffer, bytes_read);
		current->size = bytes_read;
		if (!(current->next = malloc(sizeof(t_buf_list))))
			return (-1);
		init_list_elem(current->next);
		current = current->next;
	}
	if (bytes_read)
		return (-1);
	display(first, offset);
	clear_mem(first);
	return (0);
}
