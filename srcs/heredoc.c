/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:14:49 by stan              #+#    #+#             */
/*   Updated: 2024/06/25 19:14:49 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc(const char *limiter)
{
	t_fstream	*fs;
	char		*line;
	int			pipefd[2];

	if (pipe(pipefd))
		return (-1);
	fs = fs_create("/dev/stdin");
	if (!fs)
		return (-1);
	ft_printf("heredoc> ");
	while (fs_getline(fs, &line, "\n") && !ft_strequ(limiter, line))
	{
		ft_printf("heredoc> ");
		ft_dprintf(pipefd[1], "%s\n", line);
		free(line);
	}
	if (line)
		free(line);
	fs_destroy(fs);
	close(pipefd[1]);
	return (pipefd[0]);
}
