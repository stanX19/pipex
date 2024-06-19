#include "pipex.h"

// void	exec_command(const char *command, char *const*envp)
// {
// 	char			*file;
// 	char			**argv;
// 	t_stringstream	*ss;

// 	ss = ss_create(command);
// 	ss_read_argv(ss, &file);
// 	// extract argv from command, can use ss
// 	// find file's full name
// 	execve(file, argv, envp);
// }

// int	main(int argc, char *const*argv, char *const*envp)
// {

// }

int	main(void)
{
	char			**argv;
	int				len;

	argv = ft_str_to_argv("  \"hello mother\\\"   \" fucker", &len);
	int	i;
	
	i = 0;
	while (i < len)
	{
		printf("|%s|\n", argv[i]);
		i++;
	}
	ft_free_2d((void **)argv, len);
	return 0;
}
