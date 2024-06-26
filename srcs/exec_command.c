/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:14:37 by stan              #+#    #+#             */
/*   Updated: 2024/06/26 12:32:40 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_executable(const char *name, char *const *envp)
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
		if (argv[0][0] == '/')
			ft_dprintf(2, "no such file or directory: %s\n", argv[0]);
		else
			ft_dprintf(2, "command not found: %s\n", argv[0]);
		ft_free_2d((void **)argv, argc);
		return ;
	}
	execve(executable, argv, envp);
	perror(argv[0]);
	ft_free_2d((void **)argv, argc);
	free(executable);
}
