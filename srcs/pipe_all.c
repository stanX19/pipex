/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:14:59 by stan              #+#    #+#             */
/*   Updated: 2024/06/26 12:26:26 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	start_subprocess(const char *command, char *const *envp, int fd_in,
		int fd_out)
{
	pid_t	pid;

	if (fd_in < 0)
		return ;
	pid = fork();
	if (pid < 0)
	{
		exit_handler("fork", 1);
	}
	else if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		exec_command(command, envp);
		exit(0);
	}
}

void	pipe_all(char *const *commands, int count, int terminal_fd[2],
		char *const *envp)
{
	int pipefd[2];
	int in_fd;
	int i;

	in_fd = terminal_fd[0];
	i = 0;
	while (i < count - 1)
	{
		if (pipe(pipefd))
			exit_handler("pipe", 1);
		start_subprocess(commands[i], envp, in_fd, pipefd[1]);
		close(in_fd);
		close(pipefd[1]);
		in_fd = pipefd[0];
		i++;
	}
	start_subprocess(commands[i], envp, in_fd, terminal_fd[1]);
	close(in_fd);
	close(terminal_fd[1]);
	if (terminal_fd[1] == -1)
	{
		errno = 0;
		exit_handler("no such file or directory", 1);
	}
	exit_handler(NULL, 0);
}
