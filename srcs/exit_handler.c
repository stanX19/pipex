/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:14:45 by stan              #+#    #+#             */
/*   Updated: 2024/06/25 19:14:45 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(const char *msg, int exit_code)
{
	if (msg)
	{
		if (errno)
			perror(msg);
		else
			ft_putstr_fd(msg, 2);
	}
	while (wait(NULL) > 0)
		;
	exit(exit_code);
}
