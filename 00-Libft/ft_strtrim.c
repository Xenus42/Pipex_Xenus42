/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:47:37 by lebroue           #+#    #+#             */
/*   Updated: 2024/11/28 12:28:08 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*trim;

	if (!set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	trim = malloc(sizeof(char) * ((end + 1) - (start)));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[start], ((end + 1) - (start)));
	return (trim);
}

/*int	main(void)
{
	char str1[] = "dcabonjour123456acd";
	char set[] = "dca";
	printf("%s", ft_strtrim(str1, set));
	return (0);
}*/