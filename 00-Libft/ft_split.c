/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:35 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 23:36:39 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char sep)
{
	int	count_word;
	int	i;

	i = 0;
	count_word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			count_word++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count_word);
}

static void	ft_free_split(char **tab_word, size_t i)
{
	while (i > 0)
		free(tab_word[--i]);
	free(tab_word);
}

static char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

static size_t	len_to_next_delimiter(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *src, char sep)
{
	char	**dst;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	dst = ft_calloc(sizeof(char *), count_word(src, sep) + 1);
	if (!dst)
		return (NULL);
	while (src[j])
	{
		while (src[j] == sep)
			j++;
		if (src[j] != sep && src[j])
		{
			len = len_to_next_delimiter(&src[j], sep);
			dst[i] = ft_strndup(&src[j], len);
			if (!dst[i])
				return (ft_free_split(dst, i), NULL);
			j += len;
			i++;
		}
	}
	return (dst);
}
/*
int	main(int ac, char **av)
{
	int		i;
	char	**tab;

	i = 0;
	if (ac != 3)
		return (0);
	tab = ft_split(av[1][0], av[2][0]);
	if (!tab)
		return (-1);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i++]);
	}
	free(tab);
	return (0);
}
*/