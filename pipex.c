/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:43:36 by lebroue           #+#    #+#             */
/*   Updated: 2025/03/26 20:18:57 by lebroue          ###   ########lyon.fr   */
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



// void	dup_fd()

// void	close_fd(int fd)
// {
// 	if (close(fd) == -1)
// 		exit_error();
// }

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

char	*get_path(char **envp, char *argv_cmd, int *ret)
{
	char	*path;
	char	**paths;
	char	*buffer;
	int		i;
	char	*new_path;

	i = 0;
	if (!argv_cmd || !envp && access(cmd) == -1)
	
	if (!envp || !argv_cmd)
	{
		*ret = 127;
		return (NULL);
	}
	if (argv_cmd[0] == '/')
	{
		if (access(argv_cmd, F_OK | X_OK) == 0)
			return (argv_cmd);
		else
		{
			*ret = 127;
			return (NULL);
		}
	}
	path = envp_search(envp);
	if (path == NULL)
	{
		*ret = 127;
		return (NULL);
	}
	paths = ft_split(path, ':');
	while (paths[i])
	{
		buffer = ft_strjoin(paths[i], "/");
		new_path = ft_strjoin(buffer, argv_cmd);
		free(buffer);
		dprintf(1, "%s\n", new_path);
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
void	parent_process_error_and_close_fd_exit(int *fd, int out)
{
	if (out == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(out);
		perror("open");
		exit(errno);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(out);
		perror("dup failed");
		exit(errno);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(out);
		perror("dup failed");
		exit(errno);
	}
}
void	execve_free_error_exit(char *path, char **buffer)
{
	free(path);
	ft_free_tab_str(buffer);
	perror("execve failed");
	exit(errno);
}

void	path_error_free_and_exit(int ret, char **buffer)
{
	ft_free_tab_str(buffer);
	perror("Path not found");
	exit(ret);
}

void	exec_parent_process(char **envp, char **argv, int *fd)
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
		out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		parent_process_error_and_close_fd_exit(fd, out);
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
}

void	child_process_error_and_close_fd_exit(int *fd, int in) // Child process
{
	if (in == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(in);
		perror("open");
		exit(errno);
	}
	if (dup2(in, STDIN_FILENO) == -1)
	{
		perror("dup failed");
		close(fd[0]);
		close(fd[1]);
		close(in);
		exit(errno);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup failed");
		close(fd[0]);
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
	in = open(argv[1], O_RDONLY);
	child_process_error_and_close_fd_exit(fd, in);
	close(in);
	close(fd[1]);
	buffer = ft_split(argv[2], ' ');
	if (!buffer)
		exit(EXIT_FAILURE);
	path = get_path(envp, buffer[0], &ret);
	if (path == NULL)
	{
		perror("Path not found");
		ft_free_tab_str(buffer);
		exit(ret);
	}
	execve(path, buffer, envp);
	execve_free_error_exit(path, buffer);
}
int	argc_error_and_close_fd_exit(int *fd) /// main process
{
	close(fd[0]);
	close(fd[1]);
	write(2, "ERROR\n", 6);
	return (-1);
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

int	main(int ac, char **av, char **envp)
{
	int	pid;
	int	fd[2];
	int	status;
	int	ret1;
	int	ret2;

	// if ()
	// if (!envp)
	//     verif_cmd()
	if (ac != 5)
		argc_error_and_close_fd_exit(fd);
	status = 0;
	if (pipe(fd) == -1)
		pipe_process_error_and_close_fd_exit(fd);
	pid = fork();
	if (pid == -1)
		fork_process_error_and_close_fd_exit(fd);
	if (pid == 0)
		exec_child_process(envp, av, fd);
	else
		exec_parent_process(envp, av, fd);
	close(fd[0]);
	close(fd[1]);
	wait(&status);
	ret1 = WEXITSTATUS(status);
	wait(&status);
	ret2 = WEXITSTATUS(status);
	return (ret1);
}
