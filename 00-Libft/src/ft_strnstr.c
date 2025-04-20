/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:40:10 by lebroue           #+#    #+#             */
/*   Updated: 2024/11/28 12:28:04 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (little[j] != '\0' && big[i + j] == little[j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	const char	str3[] = "Bonjour ca va ?";
	const char	str4[] = "ca va ?";

	// printf("%s", strnstr(str3, str4, 5));
	printf("%s", ft_strnstr(str3, str4, 15));
	return (0);
}
*/