/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:25:49 by lebroue           #+#    #+#             */
/*   Updated: 2024/11/28 12:27:57 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (destsize != 0)
	{
		while (src[i] != '\0' && i < (destsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
const char	src[5] = "Hello";
char		dest[7] = "bonjour";

const char	src1[5] = "Hello";
char		dest1[7] = "bonjour";
printf("%zu\n", ft_strlcpy(dest, src, ft_strlen(dest)));
printf("%zu", strlcpy(dest1, src1, 5));
printf("%s", dest);
return (0);
}*/
