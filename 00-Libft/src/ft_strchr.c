/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:08:33 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 23:03:27 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((unsigned char)s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*int	main(void)
{
	char str[] = "bonxjour";
	int c = 'r' + 256;
	char str1[] = "bonxjour";
	int d = 'r' + 256;
	printf("%s\n", ft_strchr(str, c));
	printf("%s", strchr(str1, d));
	return (0);
}*/