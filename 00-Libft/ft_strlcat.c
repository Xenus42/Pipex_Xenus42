/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:43:50 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 22:05:27 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;

	i = 0;
	dest_size = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[i] != '\0' && dest_size + 1 < size)
	{
		dst[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dst[dest_size] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

/*int	main(void)
{
	char str_dest[] = "bonjour";
	const char str_src[] = "cava";
	size_t size_cat;

	size_cat = 4;
	printf("%zu", ft_strlcat(str_dest, str_src, size_cat));
	return (0);
}*/