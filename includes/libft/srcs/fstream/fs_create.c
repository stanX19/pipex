/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:12:01 by shatan            #+#    #+#             */
/*   Updated: 2024/06/23 13:06:33 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fstream	*fs_create(const char *path)
{
	t_fstream	*fs;

	fs = (t_fstream *)malloc(sizeof(t_fstream));
	if (!fs)
		return (NULL);
	fs->fd = open(path, O_RDONLY);
	if (fs->fd == -1)
	{
		free(fs);
		return (NULL);
	}
	fs->buf = (char *)ft_calloc(sizeof(char), 1);
	if (!fs->buf)
	{
		close(fs->fd);
		free(fs);
		return (NULL);
	}
	return (fs);
}
