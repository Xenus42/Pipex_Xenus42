/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:57:04 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/11 00:41:28 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		ret;
	int		fd[2];

	if (argc != 5)
		argc_error_and_close_fd_exit();
	if (pipe(fd) == -1)
		pipe_process_error_and_close_fd_exit(fd);
	pid = fork();
	if (pid == -1)
		fork_process_error_and_close_fd_exit(fd);
	if (pid == 0)
		exec_1st_child_process(envp, argv, fd);
	else
		pid = exec_2nd_child_process(envp, argv, fd);
	close(fd[0]);
	close(fd[1]);
	ret = waiting(pid, 0);
	return (ret);
}
