/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_child_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:16:35 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/10 23:14:19 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_2nd_child_process_open_and_dup2_error(int *fd, int out)
{
	if (out == -1)
	{
		close(fd[0]);
		perror("open");
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		close(out);
		perror("dup failed");
		exit(errno);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		close(fd[0]);
		close(out);
		perror("dup failed");
		exit(errno);
	}
}

pid_t	exec_2nd_child_process(char **envp, char **argv, int *fd)
{
	int		out;
	char	*path;
	char	**buffer;
	int		pid;
	int		ret;

	ret = 0;
	pid = fork();
	if (pid == -1)
		fork_process_error_and_close_fd_exit(fd);
	if (pid == 0)
	{
		close(fd[1]);
		out = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
		check_2nd_child_process_open_and_dup2_error(fd, out);
		close(out);
		close(fd[0]);
		buffer = ft_split(argv[3], ' ');
		split_check_error(buffer);
		path = get_path(envp, buffer[0], &ret);
		get_path_check_error(path, ret, buffer);
		execve(path, buffer, envp);
		execve_free_error_exit(path, buffer);
	}
	return (pid);
}
