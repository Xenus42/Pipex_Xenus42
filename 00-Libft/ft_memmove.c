/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:08:39 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 21:50:53 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*int	main(void)
{
	char dest[20] = "bonjour";
	char src[20] = "cava";
	ft_memmove(dest, src, 3);
	printf("%s\n", (char *)memmove(dest, src, 3));
	printf("%s", (char *)ft_memmove(dest, src, 3));
	return (0);
}*/