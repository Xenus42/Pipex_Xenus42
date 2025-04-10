/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:13:17 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/11 00:38:16 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_in_paths_list(char **paths, int *ret, char *buffer,
		char *argv_cmd)
{
	char	*new_path;
	int		i;

	i = 0;
	if (paths == NULL)
		return (NULL);
	while (paths[i])
	{
		buffer = ft_strjoin(paths[i], "/");
		strjoin_check_error(buffer);
		new_path = ft_strjoin(buffer, argv_cmd);
		free(buffer);
		strjoin_check_error(new_path);
		if (new_path != NULL && access(new_path, F_OK | X_OK) == 0)
		{
			ft_free_tab_str(paths);
			return (new_path);
		}
		free(new_path);
		i++;
	}
	ft_free_tab_str(paths);
	*ret = 127;
	return (NULL);
}

char	*get_path(char **envp, char *argv_cmd, int *ret)
{
	char	*path;
	char	**paths;
	char	*buffer;
	int		i;

	buffer = NULL;
	i = 0;
	if (!argv_cmd)
	{
		*ret = 1;
		return (NULL);
	}
	else
	{
		if (access(argv_cmd, F_OK | X_OK) == 0)
			return (argv_cmd);
	}
	path = envp_search(envp);
	if (path_check(path, ret) == 1)
		return (NULL);
	paths = ft_split(path, ':');
	return (get_path_in_paths_list(paths, ret, buffer, argv_cmd));
}
