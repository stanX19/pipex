/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_skip_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:26:55 by stan              #+#    #+#             */
/*   Updated: 2024/04/29 22:26:55 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// skips characters marked as cond by f
static t_stringstream	*ss_skip(t_stringstream *ss, bool (*f)(int), bool cond)
{
	char	*newpos;

	newpos = ss->pos;
	if (ss == NULL || newpos == NULL)
		return (NULL);
	while (*newpos && f(*newpos) == cond)
		++newpos;
	ss_update_pos(ss, newpos);
	return (ss);
}

// skips characters marked as true by f
t_stringstream	*ss_skip_if(t_stringstream *ss, bool (*f)(int))
{
	return (ss_skip(ss, f, true));
}

// skips until characters marked as true by f
t_stringstream	*ss_skip_if_not(t_stringstream *ss, bool (*f)(int))
{
	return (ss_skip(ss, f, false));
}
