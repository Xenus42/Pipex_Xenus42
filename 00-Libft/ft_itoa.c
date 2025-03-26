/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:28:19 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 23:37:08 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			size;
	long int	nb;
	char		*str_char;

	nb = n;
	size = ft_nbrlen(n);
	str_char = malloc(sizeof(char) * (size + 1));
	if (!str_char)
		return (NULL);
	if (nb == 0)
		str_char[0] = '0';
	str_char[size--] = '\0';
	if (nb < 0)
	{
		str_char[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str_char[size--] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (n < 0)
		str_char[0] = '-';
	return (str_char);
}

/*int	main(void)
{
	int nb;

	nb = -01;
	printf("%s", ft_itoa(nb));
	return (0);
}*/