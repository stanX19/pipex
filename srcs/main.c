#include "pipex.h"

void	exec_command(const char *command, char *const*envp)
{
	char			*file;
	char			**argv;
	t_stringstream	*ss;

	ss = ss_create(command);
	ss_read_argv(ss, &file)
	// extract argv from command, can use ss
	// find file's full name
	execve(file, argv, envp);
}

int	main(int argc, char *const*argv, char *const*envp)
{

}
