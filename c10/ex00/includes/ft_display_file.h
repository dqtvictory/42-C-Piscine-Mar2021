/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:49:29 by qdam              #+#    #+#             */
/*   Updated: 2021/03/29 15:08:21 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# define BF_SZ 4096

# define FNAME_MISSING "File name missing.\n"
# define TOO_MANY_ARGS "Too many arguments.\n"
# define CANT_READ "Cannot read file.\n"

int		len(char *str);
void	ft_putstr(int fd, char *str);
int		error(char *msg);
int		read_from(char *fname);

#endif
