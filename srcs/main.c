#include "pipex.h"

char	**get_paths(char *const *envp)
{
	while (*envp && !ft_strnequ(*envp, "PATH", 4))
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}

char	*get_executable(const char *name, char *const *envp)
{
	int		i;
	char	**paths;
	char	*new_name;

	paths = get_paths(envp);
	new_name = NULL;
	i = 0;
	while (paths[i])
	{
		printf("DEBUG: i = %i\n", i);
		ft_strnappend(2, paths + i, "/", name);
		printf("DEBUG: paths[i] = %s\n", paths[i]);
		if (!access(paths[i], X_OK))
		{
			new_name = ft_strdup(paths[i]);
			break ;
		}
		i++;
	}
	ft_tokens_free(paths);
	return (new_name);
}

void	exec_command(const char *command, char *const *envp)
{
	char	*file;
	char	**argv;
	int		argc;

	argv = ft_str_to_argv(command, &argc);
	file = get_executable(argv[0], envp);
	execve(file, argv, envp);
	ft_free_2d((void **)argv, argc);
	free(file);
}

int	main(int argc, char *const *argv, char *const *envp)
{
	if (argc < 5)
		return (1);
	exec_command(argv[2], envp);
}

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