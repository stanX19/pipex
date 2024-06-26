/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:46:54 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 13:03:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// returns a copy of the string stored in stringstream
char	*ss_getstr(t_stringstream *ss)
{
	if (ss == NULL || ss->str == NULL)
	{
		return (NULL);
	}
	return (ft_strdup(ss->str));
}
