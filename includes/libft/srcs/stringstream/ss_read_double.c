/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_read_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:36:21 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 23:20:15 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// success	: t_stringstream pointer,	val=long double,		errno=0
// no read	: NULL,						val=0,					errno=EINVAL
t_stringstream	*ss_read_long_double(t_stringstream *ss, long double *val)
{
	char	*newpos;

	*val = 0;
	if (ss_read_precheck(ss))
		return (NULL);
	*val = ft_strtold(ss->pos, &newpos);
	return (ss_read_get_return(ss, newpos));
}

t_stringstream	*ss_read_double(t_stringstream *ss, double *val)
{
	t_stringstream	*ret;
	long double		val_long;

	ret = ss_read_long_double(ss, &val_long);
	*val = val_long;
	return (ret);
}
