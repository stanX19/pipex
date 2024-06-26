/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:14:34 by stan              #+#    #+#             */
/*   Updated: 2024/06/25 19:14:35 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>

void	exit_handler(const char *msg, int exit_code);
void	exec_command(const char *command, char *const *envp);
void	pipe_all(char *const *commands, int count, int terminal_fd[2],
			char *const *envp);
int		here_doc(const char *limiter);

#endif // PIPEX