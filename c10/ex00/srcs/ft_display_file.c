/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:45:54 by qdam              #+#    #+#             */
/*   Updated: 2021/03/29 15:08:06 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_display_file.h"

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

int		error(char *msg)
{
	ft_putstr(STDERR_FILENO, msg);
	return (1);
}

int		read_from(char *fname)
{
	char	buffer[BF_SZ];
	int		fd;
	long	bytes_read;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((bytes_read = read(fd, buffer, BF_SZ)) > 0)
		write(1, buffer, bytes_read);
	close(fd);
	if (bytes_read)
		return (-1);
	return (0);
}
