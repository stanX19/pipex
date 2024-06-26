/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_read_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:10:13 by stan              #+#    #+#             */
/*   Updated: 2024/04/29 23:23:50 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// integer version of ss_read_long
// set val to the next integer occurance
// errno will be set to ERANGE upon int overflow
// returns NULL upon failure
t_stringstream	*ss_read_int(t_stringstream *ss, int *val)
{
	t_stringstream	*ret;
	long int		val_long;

	ret = ss_read_long(ss, &val_long);
	*val = val_long;
	if (errno == 0 && ret != NULL)
	{
		if (val_long < INT_MIN)
		{
			*val = INT_MIN;
			errno = ERANGE;
		}
		else if (val_long > INT_MAX)
		{
			*val = INT_MAX;
			errno = ERANGE;
		}
	}
	return (ret);
}
