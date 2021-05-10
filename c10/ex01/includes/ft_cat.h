/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:35:55 by qdam              #+#    #+#             */
/*   Updated: 2021/03/29 15:08:26 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <libgen.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

# define BF_SZ 4096

int		len(char *str);
int		read_from(char *fname);
void	ft_putstr(int fd, char *str);
void	put_err(char *pname, char *fname, char *msg);

#endif
