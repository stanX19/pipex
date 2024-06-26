/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:08:59 by shatan            #+#    #+#             */
/*   Updated: 2024/06/22 18:10:48 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUF_SIZE 1024

static int	extend_buffer(t_fstream *fs)
{
	static char	buf[BUF_SIZE + 1];
	int			bytes_read;

	bytes_read = read(fs->fd, buf, BUF_SIZE);
	if (bytes_read == 0)
		return (0);
	buf[bytes_read] = '\0';
	ft_str_append(&fs->buf, buf);
	return (bytes_read);
}

static int	find_end_of_line(t_fstream *fs, char *seps)
{
	int	idx;

	idx = 0;
	while (true)
	{
		if (fs->buf[idx] == '\0')
			extend_buffer(fs);
		if (fs->buf[idx] == '\0' || ft_strchr(seps, fs->buf[idx]) != NULL)
			break ;
		++idx;
	}
	return (idx);
}

t_fstream	*fs_getline(t_fstream *fs, char **strptr, char *seps)
{
	int		idx;

	if (!fs || !fs->fd)
		return (NULL);
	if (strptr)
		*strptr = NULL;
	idx = find_end_of_line(fs, seps);
	if (fs->buf[0] == '\0')
	{
		return (NULL);
		fs->flag = FS_EOF;
	}
	if (strptr)
		*strptr = ft_strndup(fs->buf, idx);
	ft_memmove(fs->buf, fs->buf + idx + 1, ft_strlen(fs->buf + idx + 1) + 1);
	return (fs);
}
