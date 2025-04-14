/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_child_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:12:59 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/14 14:57:43 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_1st_child_process_open_and_dup2_error(int *fd, int in)
{
	if (in == -1)
	{
		perror("open");
		close(fd[1]);
		close(in);
		exit(errno);
	}
	if (dup2(in, STDIN_FILENO) == -1)
	{
		perror("dup failed");
		close(fd[1]);
		close(in);
		exit(errno);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup failed");
		close(fd[1]);
		close(in);
		exit(errno);
	}
}

void	exec_1st_child_process(char **envp, char **argv, int *fd)
{
	int		in;
	char	*path;
	char	**buffer;
	int		ret;

	ret = 0;
	close(fd[0]);
	if (access(argv[1], R_OK | F_OK) == -1)
	{
		perror("ERROR");
		close(fd[1]);
		exit(1);
	}
	in = open(argv[1], O_RDONLY);
	check_1st_child_process_open_and_dup2_error(fd, in);
	close(in);
	close(fd[1]);
	buffer = ft_split(argv[2], ' ');
	if (!buffer)
		exit(1);
	path = get_path(envp, buffer[0], &ret);
	if (path == NULL)
		path_error_free_and_exit(ret, buffer);
	execve(path, buffer, envp);
	execve_free_error_exit(path, buffer);
}
