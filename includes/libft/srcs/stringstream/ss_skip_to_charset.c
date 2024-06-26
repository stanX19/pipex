/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_skip_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:54:31 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 13:04:21 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// skips until occurance of characters specified in charset
t_stringstream	*ss_skip_to_charset(t_stringstream *ss, const char *charset)
{
	char	*newpos;

	newpos = ss->pos;
	if (ss == NULL || newpos == NULL)
		return (NULL);
	while (ft_strchr(charset, *newpos) == NULL)
	{
		++newpos;
	}
	ss_update_pos(ss, newpos);
	return (ss);
}
