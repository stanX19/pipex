/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_skip_nchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:54:35 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 13:04:08 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// skips n number of characters from current position
t_stringstream	*ss_skip_nchar(t_stringstream *ss, size_t n)
{
	size_t	i;
	char	*newpos;

	newpos = ss->pos;
	if (ss == NULL || newpos == NULL)
		return (NULL);
	i = 0;
	while (i < n && *newpos)
	{
		++newpos;
		++i;
	}
	ss_update_pos(ss, newpos);
	return (ss);
}
