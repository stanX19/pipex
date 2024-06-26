/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:28:10 by stan              #+#    #+#             */
/*   Updated: 2024/06/26 15:55:47 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_normal_io(int terminal_fd[2], int argc, char *const *argv)
{
	terminal_fd[0] = open(argv[1], O_RDONLY);
	terminal_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (terminal_fd[0] < 0)
	{
		ft_dprintf(2, "no such file or directory: %s\n", argv[1]);
	}
}

static void	set_heredoc_io(int terminal_fd[2], int argc, char *const *argv)
{
	terminal_fd[0] = here_doc(argv[2]);
	terminal_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	if (terminal_fd[0] < 0)
	{
		ft_dprintf(2, "no such file or directory: %s\n", argv[1]);
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
// 	t_fstream	*fs;
// 	char *str;
// 	int argc;
// 	char **argv;

// 	fs = fs_create("/dev/stdin");
// 	ft_printf(">>> ");
// 	while (fs_getline(fs, &str, "\n"))
// 	{
// 		argv = ft_str_to_argv(str, &argc);
// 		for(int i = 0; i < argc; i++)
// 		{
// 			ft_printf("|%s|\n", argv[i]);
// 		}
// 		ft_printf(">>> ");
// 		free(str);
// 		ft_free_2d((void **)argv, argc);
// 	}
// }
