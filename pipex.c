/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:43:36 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/08 01:27:51 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./00-Libft/libft.h"
#include "pipex.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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

////// GET_PATH FUNCTION + UTILS //////

int	path_check(char *path, int *ret)
{
	if (path == NULL)
	{
		*ret = 127;
		return (1);
	}
	return (0);
}

char	*get_path_in_paths(char **paths, int *ret, char *buffer, char *argv_cmd)
{
	char	*new_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		buffer = ft_strjoin(paths[i], "/");
		new_path = ft_strjoin(buffer, argv_cmd);
		free(buffer);
		if (access(new_path, F_OK | X_OK) == 0)
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
	return (get_path_in_paths(paths, ret, buffer, argv_cmd));
}
////////////////////////////////////////////////////////////////

void	parent_process_open_and_dup2_error(int *fd, int out)
{
	if (out == -1)
	{
		close(fd[0]);
		close(out);
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

pid_t	exec_parent_process(char **envp, char **argv, int *fd)
{
	int		out;
	char	*path;
	char	**buffer;
	int		pid;
	int		ret;

	ret = 0;
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		out = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
		parent_process_open_and_dup2_error(fd, out);
		close(out);
		close(fd[0]);
		buffer = ft_split(argv[3], ' ');
		if (!buffer)
			exit(EXIT_FAILURE);
		path = get_path(envp, buffer[0], &ret);
		if (path == NULL)
			path_error_free_and_exit(ret, buffer);
		execve(path, buffer, envp);
		execve_free_error_exit(path, buffer);
	}
	return (pid);
}

void	child_process_close_and_dup2_error(int *fd, int in)
{
	if (in == -1)
	{
		perror("open");
		close(fd[1]);
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

void	exec_child_process(char **envp, char **argv, int *fd)
{
	int		in;
	char	*path;
	char	**buffer;
	int		ret;

	ret = 0;
	close(fd[0]);
	if (access(argv[1], R_OK | F_OK) == -1)
	{
		perror("test");
		exit(1);
	}
	in = open(argv[1], O_RDONLY);
	child_process_close_and_dup2_error(fd, in);
	close(in);
	close(fd[1]);
	buffer = ft_split(argv[2], ' ');
	if (!buffer)
		exit(EXIT_FAILURE);
	path = get_path(envp, buffer[0], &ret);
	if (path == NULL)
		path_error_free_and_exit(ret, buffer);
	execve(path, buffer, envp);
	execve_free_error_exit(path, buffer);
}
int	argc_error_and_close_fd_exit(void) /// main process
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int	pipe_process_error_and_close_fd_exit(int *fd) // main process
{
	close(fd[0]);
	close(fd[1]);
	perror("pipe failed");
	exit(errno);
}

int	fork_process_error_and_close_fd_exit(int *fd) // main process
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

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		ret;

	int fd[2]; // (fd[0] && fd[1])
	if (ac != 5)
		argc_error_and_close_fd_exit();
	if (pipe(fd) == -1)
		pipe_process_error_and_close_fd_exit(fd);
	pid = fork();
	if (pid == -1)
		fork_process_error_and_close_fd_exit(fd);
	if (pid == 0)
		exec_child_process(envp, av, fd);
	else
		pid = exec_parent_process(envp, av, fd);
	close(fd[0]);
	close(fd[1]);
	ret = waiting(pid, 0);
	return (ret);
}
