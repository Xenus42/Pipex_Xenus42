/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:43:36 by lebroue           #+#    #+#             */
/*   Updated: 2025/03/21 19:50:30 by lebroue          ###   ########lyon.fr   */
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
	while (ft_strncmp("PATH=", *envp, 5))
	{
		envp++;
	}
	return (*envp + 5);
}

char	*get_path(char **envp, char *argv_cmd, int *ret)
{
	char	*path;
	char	**paths;
	char	*buffer;
	int		i;
	char	*new_path;

	i = 0;
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
	paths = ft_split(path, ':');
	while (paths[i])
	{
		buffer = ft_strjoin(paths[i], "/");
		new_path = ft_strjoin(buffer, argv_cmd);
		// dprintf(2, "path = %s\n", new_path);
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
// void	parent_process_error_close(int *fd, int out)
// {
// 	if (out == -1)
// 		{
// 			close(fd[0]);
// 			close(fd[1]);
// 			perror("open");
// 			exit(errno);
// 		}
// 		// dprintf(2, "fd == %d\n", fd[0]);
// 		if (dup2(fd[0], STDIN_FILENO) == -1)
// 		{
// 			close(fd[0]);
// 			close(fd[1]);
// 			perror("dup failed");
// 			exit(errno);
// 		}
// 		if (dup2(out, STDOUT_FILENO) == -1)
// 		{
// 			close(fd[0]);
// 			close(fd[1]);
// 			perror("dup failed");
// 			exit(errno);
// 		}
	
// }
void	exec_parent_process(char **envp, char **argv, int *fd)
////sortir les fonctions-protections des fd
{
	int out;
	char *path;
	char **buffer;
	int pid;
	int ret;

	ret = 0;
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (out == -1)
		{
			close(fd[0]);
			close(fd[1]);
			perror("open");
			exit(errno);
		}
		// dprintf(2, "fd == %d\n", fd[0]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			perror("dup failed");
			exit(errno);
		}
		if (dup2(out, STDOUT_FILENO) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			perror("dup failed");
			exit(errno);
		}
		dprintf(2, "KKKKKKKKKKKKKKKK\n");
		close(out);
		close(fd[0]);
		buffer = ft_split(argv[3], ' ');
		if (!buffer)
			exit(EXIT_FAILURE);
		path = get_path(envp, buffer[0], &ret);
		if (path == NULL)
		{
			perror("Path not found");
			ft_free_tab_str(buffer);
			exit(ret);
		}
		if (execve(path, buffer, envp) == -1)
		{
			free(path);
			ft_free_tab_str(buffer);
			perror("execve failed");
			exit(errno);
		}
	}
}
// void	child_process_error_close(int *fd, int in)
// {	
// 	if (in == -1)
// 	{
// 		close(fd[0]);
// 		close(fd[1]);
// 		perror("open");
// 		exit(errno);
// 	}
// 	if (dup2(in, STDIN_FILENO) == -1)
// 	{
// 		perror("dup failed");
// 		close(fd[0]);
// 		close(fd[1]);
// 		close(in);
// 		exit(errno);
// 	}
// 	if (dup2(fd[1], STDOUT_FILENO) == -1)
// 	{
// 		perror("dup failed");
// 		close(fd[0]);
// 		close(fd[1]);
// 		close(in);
// 		exit(errno);
// 	}
// }
void	exec_child_process(char **envp, char **argv, int *fd)
////sortir les fonctions-protections des fd
{
	int in;
	char *path;
	char **buffer;
	int ret;

	ret = 0;
	in = open(argv[1], O_RDONLY);
	close(fd[0]);
	// child_process_error_close(fd, in);
	if (in == -1)
	{
		close(fd[0]);
		close(fd[1]);
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
	free(path);
	ft_free_tab_str(buffer);
	perror("execve failed");
	exit(errno);
}

int	main(int ac, char **av, char **envp)
{
	int	pid;
	int	fd[2];
	int	status;
	int	ret1;
	int	ret2;

	// if (!envp)
	//     verif_cmd()
	if (ac != 5)
	{
		write(2, "ERROR\n", 6);
		return (-1);
	}
	status = 0;
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		exit(errno);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(errno);
	}
	if (pid == 0)
		exec_child_process(envp, av, fd);
	else
		exec_parent_process(envp, av, fd);
	close(fd[0]);
	close (fd[1]);
	wait(&status);
	ret1 = WEXITSTATUS(status);
	dprintf(2, "KKKKKKKKKKKKKKKK2\n");
	wait(&status);
	ret2 = WEXITSTATUS(status);
	// dprintf(2, "%d\n%d\n",ret1, ret2);
	return (ret1);
}

////securiser Dup2 !!!! DONE
////securiser ACCESS !!! DONE
