/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_skip_non_numeric.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:54:31 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 13:04:12 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// skips until occurance of numeric characters "0123456789+-."
t_stringstream	*ss_skip_to_numeric(t_stringstream *ss)
{
	char	*newpos;

	newpos = ss->pos;
	if (ss == NULL || newpos == NULL)
		return (NULL);
	while (*newpos != '\0' && !ft_isnumeric(newpos))
	{
		++newpos;
	}
	ss_update_pos(ss, newpos);
	return (ss);
}
