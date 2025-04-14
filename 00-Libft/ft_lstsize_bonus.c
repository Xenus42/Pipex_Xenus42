/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 02:00:01 by lebroue           #+#    #+#             */
/*   Updated: 2025/01/28 19:13:23 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb_of_node;

	nb_of_node = 0;
	while (lst != NULL)
	{
		nb_of_node++;
		lst = lst->next;
	}
	return (nb_of_node);
}
/*#include "stdio.h"

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	int	i;

	i = 10;
	lst = NULL;
	while (--i)
	{
		new = ft_lstnew(i);
		ft_lstadd_front(&lst, new);
		
	}
	while (lst != NULL)
	{
		printf("lst.content = %d\n", lst->content);
		lst = lst->next;
	}
}*/