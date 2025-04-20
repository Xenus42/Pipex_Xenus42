/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:11:32 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 21:57:52 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char	str[] = "bonjour1";
	int		c;

	c = '0';
	printf("%s\n", (char *)memset(str, c, 6));
	printf("%s", (char *)ft_memset(str, c, 6));
	return (0);
}*/
