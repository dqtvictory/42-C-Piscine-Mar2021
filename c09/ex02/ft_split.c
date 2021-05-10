/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:14:31 by qdam              #+#    #+#             */
/*   Updated: 2021/03/23 12:43:09 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *seps)
{
	int	i;

	i = 0;
	while (seps[i])
	{
		if (seps[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	copy_str(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

int		len_word(char *word, char *seps)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (is_sep(word[i], seps))
			break ;
		i++;
	}
	return (i);
}

int		count_words(char *str, char *seps)
{
	int	i;
	int	count;
	int	seen_sep;

	i = 0;
	count = 0;
	seen_sep = 1;
	while (str[i])
	{
		if (is_sep(str[i], seps))
			seen_sep = 1;
		else if (seen_sep)
		{
			count++;
			seen_sep = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		n_words;
	int		w;
	int		lw;

	n_words = count_words(str, charset);
	if (!(words = malloc(sizeof(char *) * (n_words + 1))))
		return (0);
	words[n_words] = 0;
	w = 0;
	while (*str)
	{
		if (is_sep(*str, charset))
			str++;
		else
		{
			lw = len_word(str, charset);
			if (!(words[w] = malloc(sizeof(char) * (lw + 1))))
				return (0);
			copy_str(words[w], str, lw);
			w++;
			str += lw;
		}
	}
	return (words);
}
