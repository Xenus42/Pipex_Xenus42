/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:43:06 by lebroue           #+#    #+#             */
/*   Updated: 2024/11/28 12:27:51 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (tmp[i])
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	const char *str = "bonjour";
	char *dest;
	dest = ft_strdup(str);
	printf("%s", dest);
}*/