/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:59:16 by lebroue           #+#    #+#             */
/*   Updated: 2024/11/28 12:28:00 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_result;

	i = 0;
	new_result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_result)
		return (NULL);
	while (s[i] != '\0')
	{
		new_result[i] = f(i, s[i]);
		i++;
	}
	new_result[i] = '\0';
	return (new_result);
}

/*int	main(void)
{
	const char *str = "bonjour";
	char c;
	c = 'c';
	printf("%s", ft_strmapi(str, (char *)ft_toupper((unsigned int./	)str)));
	return (0);
}*/