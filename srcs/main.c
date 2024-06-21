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
		ft_strnappend(2, &executable, "/", name);
		if (access(executable, X_OK) == 0)
			break;
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
	ft_free_2d((void **)argv, argc);
	free(executable);
}

int	main(int argc, char *const *argv, char *const *envp)
{
	int	in_fd;
	int	out_fd;

	if (argc != 5)
		return (1);
	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[4], O_RDWR | O_CREAT);
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	exec_command(argv[2], envp);
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