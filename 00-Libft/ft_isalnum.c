/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:51 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/03 23:29:51 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if (ft_isalpha(i) || ft_isdigit(i))
		return (1);
	else
		return (0);
}

/*int 	main(void)
{
	printf("%d", ft_isalnum('\n'));
			return (0);
}*/
