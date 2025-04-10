/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:01:08 by lebroue           #+#    #+#             */
/*   Updated: 2025/04/11 00:38:05 by lebroue          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./00-Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

///////////////////GET-PATH UTILS /////////////////////////


/*FREE TAB*/

void	ft_free_tab_str(char **str);

/*ENVP-SEARCH*/

char	*envp_search(char **envp);

/*PATH-CHECK*/

int		path_check(char *path, int *ret);

/*STRJOIN-CHECK*/

char	*strjoin_check_error(char *str);


///////////////////////// GET-PATH //////////////////////////


/*GET PATH FUNCTION*/

char	*get_path(char **envp, char *argv_cmd, int *ret);

/*GET PATH FUNCTION IN PATHS LIST(SUITE)*/

char	*get_path_in_paths_list(char **paths, int *ret, char *buffer,
			char *argv_cmd);


///////////////// 2ND-CHILD PROCESS UTILS  //////////////////////////


/*EXECVE PROTECTION*/

void	execve_free_error_exit(char *path, char **buffer);

/*PATH PROTECTION*/

void	path_error_free_and_exit(int ret, char **buffer);

/*SPLIT PROTECTION*/

void	split_check_error(char **buffer);

/*GET-PATH PROTECTION*/

void	get_path_check_error(char *path, int ret, char **buffer);


//////////////////////// 2ND-CHILD PROCESS //////////////////////////


/*EXEC 2ND CHILD*/

pid_t	exec_2nd_child_process(char **envp, char **argv, int *fd);

/*CLOSE & DUP2 PROTECTTION*/

void	check_2nd_child_process_open_and_dup2_error(int *fd, int out);


//////////////////////// 1ST-CHILD PROCESS //////////////////////////


/*EXEC 1ST CHILD*/

void	exec_1st_child_process(char **envp, char **argv, int *fd);

/*CLOSE & DUP2 PROTECTTION*/

void	check_1st_child_process_close_and_dup2_error(int *fd, int in);


////////////////////////// MAIN - UTILS  ////////////////////////////


/*ARGC PROTECTION*/

int		argc_error_and_close_fd_exit(void);

/*PIPE PROTECTION*/

int		pipe_process_error_and_close_fd_exit(int *fd);

/*FORK PROTECTION*/

int		fork_process_error_and_close_fd_exit(int *fd);

/*WAITING PID STATUS*/

int		waiting(pid_t pid, int status);


////////////////////////////// MAIN  ////////////////////////////////

int		main(int argc, char **argv, char **envp);

#endif
