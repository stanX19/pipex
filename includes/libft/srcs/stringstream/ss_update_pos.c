/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_update_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:30:07 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 13:03:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

t_stringstream	*ss_update_pos(t_stringstream *ss, char *newpos)
{
	if (!ss || !ss->pos)
		return (NULL);
	ss->prev_pos = ss->pos;
	ss->pos = newpos;
	return (ss);
}
