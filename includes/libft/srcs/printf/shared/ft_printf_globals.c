/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_globals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:08:08 by stan              #+#    #+#             */
/*   Updated: 2024/05/25 18:12:08 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	*printf_fd(void)
{
	static int	fd = 1;

	return (&fd);
}

int	ft_printf_fd_get(void)
{
	return (*printf_fd());
}

void	ft_printf_fd_set(int fd)
{
	(*printf_fd()) = fd;
}
