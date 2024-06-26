/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_read_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:55:35 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 23:23:19 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// success	: t_stringstream pointer,	val=long,				errno=0
// eof		: NULL,						val=0,					errno=0
// overflow	: NULL,						val=LONG_MAX/LONG_MIN,	errno=ERANGE
// fail		: NULL,						val=0,					errno=EINVAL
t_stringstream	*ss_read_long(t_stringstream *ss, long int *val)
{
	char	*newpos;

	*val = 0;
	if (ss_read_precheck(ss))
		return (NULL);
	*val = ft_strtol(ss->pos, &newpos, "0123456789");
	return (ss_read_get_return(ss, newpos));
}
