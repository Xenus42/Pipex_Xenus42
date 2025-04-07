/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:01:08 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/08 01:32:07 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */




#ifndef PIPEX_H
# define PIPEX_H

# define ERR_MALLOC 12

#endif

void	ft_free_tab_str(char **str);

char	*envp_search(char **envp);

int	path_check(char *path, int *ret);

char	*get_path_in_paths(char **paths, int *ret, char *buffer, char *argv_cmd);

char	*get_path(char **envp, char *argv_cmd, int *ret);

void	parent_process_open_and_dup2_error(int *fd, int out);

void	execve_free_error_exit(char *path, char **buffer);

void path_error_free_and_exit(int ret, char **buffer);

pid_t	exec_parent_process(char **envp, char **argv, int *fd);

void	child_process_close_and_dup2_error(int *fd, int in);

void	exec_child_process(char **envp, char **argv, int *fd);

int	argc_error_and_close_fd_exit(void);

int	pipe_process_error_and_close_fd_exit(int *fd);

int	fork_process_error_and_close_fd_exit(int *fd);

int	waiting(pid_t pid, int status);

int	main(int ac, char **av, char **envp);
