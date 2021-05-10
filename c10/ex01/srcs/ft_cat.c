/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:06:22 by qdam              #+#    #+#             */
/*   Updated: 2021/03/29 15:08:03 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int		len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	write(fd, str, len(str));
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

int		read_from(char *fname)
{
	char	buffer[BF_SZ];
	int		fd;
	long	bytes_read;

	fd = !fname ? STDIN_FILENO : open(fname, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((bytes_read = read(fd, buffer, BF_SZ)) > 0)
		write(1, buffer, bytes_read);
	if (fd != STDIN_FILENO)
		close(fd);
	if (bytes_read)
		return (-1);
	return (0);
}
