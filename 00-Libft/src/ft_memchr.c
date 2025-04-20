/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:31:24 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 21:41:22 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;

	tmp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
			return ((void *)&tmp_s[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char str[] = "Bonjour";
	int letter ;
	letter = 'j';
	printf("%s\n", (char *)ft_memchr(str, l, 7));
	printf("%s", (char *)memchr(str, l, 7));
	return (0);
}*/