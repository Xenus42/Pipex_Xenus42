/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:04:11 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 21:42:27 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (i < n)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char str1[] = "bonjour";
	char str2[] = "Bonjour";
	char str3[] = "bonjour";
	char str4[] = "Bonjour";
	printf("%d\n", ft_memcmp(str1, str2, 2));
	printf("%d", memcmp(str3, str4, 2));
}*/