/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:29:57 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/11 00:41:01 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*envp_search(char **envp)
{
	if (!envp || !*envp)
		return (NULL);
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

int	path_check(char *path, int *ret)
{
	if (path == NULL)
	{
		*ret = 127;
		return (1);
	}
	return (0);
}

char	*strjoin_check_error(char *str)
{
	if (!str)
		return (NULL);
	return (str);
}
