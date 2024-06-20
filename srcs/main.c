#include "pipex.h"

// char	*get_executable(const char *name)
// {
	
// }

// void	exec_command(const char *command, char *const*envp)
// {
// 	char			*file;
// 	char			**argv;
// 	int				argc;

// 	argv = ft_str_to_argv(command, &argc);

// }

// int	main(int argc, char *const*argv, char *const*envp)
// {

// }

int main(void)
{
	char *str = "hello\\\\\\\\ mother *******";
	int argc;
	char **argv = ft_str_to_argv(str, &argc);

	for(int i = 0; i < argc; i++)
	{
		printf("|%s|\n", argv[i]);
	}
	ft_free_2d((void **)argv, argc);
}