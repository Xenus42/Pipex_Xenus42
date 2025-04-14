/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:22:33 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/14 14:01:17 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	argc_error_and_close_fd_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(errno);
}

int	pipe_process_error_and_close_fd_exit(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	perror("pipe failed");
	exit(errno);
}

int	fork_process_error_and_close_fd_exit(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	perror("fork failed");
	exit(errno);
}

int	waiting(pid_t pid, int status)
{
	int		ret;
	pid_t	pid_at_exit;

	while (1)
	{
		pid_at_exit = wait(&status);
		if (pid_at_exit == pid)
			ret = WEXITSTATUS(status);
		if (pid_at_exit < 0)
			break ;
	}
	return (ret);
}
