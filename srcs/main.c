/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:28:10 by stan              #+#    #+#             */
/*   Updated: 2024/06/25 19:14:53 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_normal_io(int terminal_fd[2], int argc, char *const *argv)
{
	terminal_fd[0] = open(argv[1], O_RDONLY);
	if (terminal_fd[0] < 0)
	{
		exit_handler(argv[1], 0);
	}
	terminal_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (terminal_fd[1] < 0)
	{
		close(terminal_fd[0]);
		exit_handler(argv[argc - 1], 1);
	}
}

static void	set_heredoc_io(int terminal_fd[2], int argc, char *const *argv)
{
	terminal_fd[0] = here_doc(argv[2]);
	if (terminal_fd[0] < 0)
	{
		exit_handler(argv[1], 0);
	}
	terminal_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	if (terminal_fd[1] < 0)
	{
		close(terminal_fd[0]);
		exit_handler(argv[argc - 1], 1);
	}
}

int	main(int argc, char *const *argv, char *const *envp)
{
	int	terminal_fd[2];

	if (argc < 4)
	{
		ft_dprintf(2, "Error: too few arguments\n");
		return (1);
	}
	if (ft_strequ(argv[1], "here_doc"))
	{
		set_heredoc_io(terminal_fd, argc, argv);
		pipe_all(argv + 3, argc - 4, terminal_fd, envp);
	}
	else
	{
		set_normal_io(terminal_fd, argc, argv);
		pipe_all(argv + 2, argc - 3, terminal_fd, envp);
	}
	return (0);
}

// (void)argv;
// (void)argc;
// (void)envp;
// printf("DEBUG: access(\"./pipex\", X_OK) = %i\n", access("./pipex", X_OK));

// int main(void)
// {
// 	char *str = "hello\\\\\\\\ mother *******";
// 	int argc;
// 	char **argv = ft_str_to_argv(str, &argc);

// 	for(int i = 0; i < argc; i++)
// 	{
// 		printf("|%s|\n", argv[i]);
// 	}
// 	ft_free_2d((void **)argv, argc);
// }