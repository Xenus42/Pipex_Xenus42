/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:33:36 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 21:44:03 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (!src && !dest)
		return (dest);
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char dst[] = "bonjour";
	char src[] = "tresbeau";
	char dst1[] = "bonjour";
	char src1[] = "tresbeau";
	printf("%s\n", (char *)ft_memcpy(dst, src, 3));
	printf("%s\n", (char *)memcpy(dst1, src1, 3));
}*/