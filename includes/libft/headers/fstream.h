/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:56:47 by shatan            #+#    #+#             */
/*   Updated: 2024/06/26 15:56:47 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSTREAM_H
# define FSTREAM_H
# include "libft.h"

typedef enum e_fstream_flag
{
	FS_OK,
	FS_EOF
}					t_fstream_flag;

typedef struct s_fstream
{
	int				fd;
	char			*buf;
	t_fstream_flag	flag;
}					t_fstream;

t_fstream			*fs_create(const char *path);
void				fs_destroy(t_fstream *fs);
t_fstream			*fs_getline(t_fstream *fs, char **strptr, char *seps);

#endif // FSTREAM