/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_child_process_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:17:08 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/11 00:40:35 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_free_error_exit(char *path, char **buffer)
{
	perror("execve failed");
	free(path);
	ft_free_tab_str(buffer);
	exit(errno);
}

void	path_error_free_and_exit(int ret, char **buffer)
{
	perror("Path not found");
	ft_free_tab_str(buffer);
	exit(ret);
}

void	split_check_error(char **buffer)
{
	if (!buffer)
		exit(EXIT_FAILURE);
}

void	get_path_check_error(char *path, int ret, char **buffer)
{
	if (path == NULL)
		path_error_free_and_exit(ret, buffer);
}
