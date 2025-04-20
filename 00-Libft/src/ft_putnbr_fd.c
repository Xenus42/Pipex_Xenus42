/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:54:57 by lebroue           #+#    #+#             */
/*   Updated: 2024/12/06 23:50:24 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
		}
		else
		{
			n *= -1;
			write(fd, "-", 1);
			ft_putnbr_fd(n, fd);
		}
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

/*int	main(void)
{
	int nb;
	int fd;
	nb = -2145664654;
	fd = 1;
	ft_putnbr_fd(nb, fd);
	return (0);
}*/