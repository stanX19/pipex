/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_recreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:26:07 by shatan            #+#    #+#             */
/*   Updated: 2024/06/26 15:56:17 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// creates stringstring from str, the stored version is a copy from strdup
t_stringstream	*ss_recreate(t_stringstream *ss, const char *str)
{
	if (!ss)
		return (NULL);
	if (ss->str)
		free(ss->str);
	ss->str = ft_strdup(str);
	ss->pos = ss->str;
	ss->prev_pos = NULL;
	if (!ss->str)
		return (NULL);
	return (ss);
}
