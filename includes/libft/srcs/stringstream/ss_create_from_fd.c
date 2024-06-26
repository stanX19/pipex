/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_create_from_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:05:34 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 18:54:47 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

t_stringstream	*ss_create_from_fd(int fd)
{
	char			buffer[4096];
	ssize_t			rd_size;
	t_stringstream	*ss;

	rd_size = 1;
	ss = ss_create("");
	errno = 0;
	while (errno == 0 && rd_size != 0)
	{
		rd_size = read(fd, buffer, sizeof(buffer) - 1);
		buffer[rd_size] = '\0';
		ss_append(ss, buffer);
	}
	return (ss);
}
