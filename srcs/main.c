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
	executable = NULL;
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
	executable = get_executable(argv[0], envp);
	execve(executable, argv, envp);
	perror("execve");
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
			exit(2);
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
	{
		wait(NULL);
	}
}

void here_doc(void)
{
	t_fstream *fs;
	char		*line;

	fs = fs_create("input.txt");
	ft_printf("here_doc>");
	while (fs_getline(fs, &line, "\n") && !ft_strequ(line, "end"))
	{
		ft_printf("|%s|\nhere_doc> ", line);
		free(line);
	}
	if (line)
		free(line);
	fs_destroy(fs);
}

int	main(int argc, char *const *argv, char *const *envp)
{
	int	in_fd;
	int	out_fd;

	if (argc < 4)
		return (1);
	in_fd = open(argv[1], O_RDONLY);
	if (!in_fd)
	{
		ft_dprintf(2, "No such file: \"%s\"", argv[1]);
		exit(1);
	}
	out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	pipe_all(argv + 2, argc - 3, (int[2]){in_fd, out_fd}, envp);
	here_doc();
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