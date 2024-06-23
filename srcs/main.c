#include "pipex.h"

char	*get_executable(const char *name, char *const *envp)
{
	char			*executable;
	t_stringstream	*ss;

	if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	while (*envp && !ft_strnequ(*envp, "PATH", 4))
		envp++;
	if (!*envp)
		return (NULL);
	ss = ss_create(*envp + 5);
	while (ss_read_line(ss, &executable, ":"))
	{
		ft_strnappend(&executable, 2, "/", name);
		if (access(executable, X_OK) == 0)
			break ;
		free(executable);
	}
	ss_destroy(ss);
	return (executable);
}

void	exec_command(const char *command, char *const *envp)
{
	char	*executable;
	char	**argv;
	int		argc;

	argv = ft_str_to_argv(command, &argc);
	if (argv == NULL)
		return ;
	executable = get_executable(argv[0], envp);
	if (executable == NULL)
	{
		ft_dprintf(2, "command not found: %s\n", argv[0]);
		ft_free_2d((void **)argv, argc);
		return ;
	}
	execve(executable, argv, envp);
	perror(argv[0]);
	ft_free_2d((void **)argv, argc);
	free(executable);
}

void	start_subprocess(const char *command, char *const *envp, int fd_in,
		int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		exec_command(command, envp);
		exit(1);
	}
}

void	pipe_all(char *const *commands, int count, int terminal_fd[2],
		char *const *envp)
{
	int	pipefd[2];
	int	in_fd;
	int	i;

	in_fd = terminal_fd[0];
	i = 0;
	while (i < count - 1)
	{
		if (pipe(pipefd))
		{
			perror("pipe");
			exit(2);
		}
		start_subprocess(commands[i], envp, in_fd, pipefd[1]);
		close(in_fd);
		close(pipefd[1]);
		in_fd = pipefd[0];
		i++;
	}
	start_subprocess(commands[i], envp, in_fd, terminal_fd[1]);
	close(in_fd);
	close(terminal_fd[1]);
	i = 0;
	while (i++ < count)
		wait(NULL);
}

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

void	set_normal_io(int terminal_fd[2], int argc, char *const *argv)
{
	terminal_fd[0] = open(argv[1], O_RDONLY);
	if (terminal_fd[0] == -1)
	{
		ft_dprintf(2, "%s: \"%s\"\n", strerror(errno), argv[1]);
		exit(0);
	}
	terminal_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (terminal_fd[1] == -1)
	{
		ft_dprintf(2, "%s: \"%s\"\n", strerror(errno), argv[argc - 1]);
		exit(1);
	}
}

void	set_heredoc_io(int terminal_fd[2], int argc, char *const *argv)
{
	terminal_fd[0] = here_doc(argv[2]);
	if (terminal_fd[0] == -1)
	{
		ft_dprintf(2, "%s: \"%s\"\n", strerror(errno), argv[1]);
		exit(0);
	}
	terminal_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	if (terminal_fd[1] == -1)
	{
		ft_dprintf(2, "%s: \"%s\"\n", strerror(errno), argv[argc - 1]);
		exit(1);
	}
}

int	main(int argc, char *const *argv, char *const *envp)
{
	int terminal_fd[2];

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