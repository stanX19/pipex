/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_destory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:15:25 by shatan            #+#    #+#             */
/*   Updated: 2024/06/22 17:45:52 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fs_destroy(t_fstream *fs)
{
	if (!fs)
		return ;
	if (fs->fd >= 0)
		close(fs->fd);
	if (fs->buf != NULL)
		free(fs->buf);
	free(fs);
}
