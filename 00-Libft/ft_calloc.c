/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:42:35 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 21:30:24 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > 2147483647 / size)
		return (NULL);
	tmp = malloc((size * nmemb));
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}

/*int	main(void)
{
	char *tmp;
	size_t len;
	size_t i;

	i = 0;
	tmp = "bonjour";
	len = strlen(tmp);
	tmp = ft_calloc(50, sizeof(char));
	//len = strlen(tmp);
	while (i < len)
	{
		printf("%i\n", tmp[i]);
		i++;
	}
	// printf("%s", (char *)ft_calloc(len, 5));
}*/