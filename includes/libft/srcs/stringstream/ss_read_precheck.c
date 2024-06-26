/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_read_precheck.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:26:39 by stan              #+#    #+#             */
/*   Updated: 2024/06/21 00:13:40 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// 0	: ok
// 1	: fail
int	ss_read_precheck(t_stringstream *ss)
{
	if (ss == NULL || ss->pos == NULL || *ss->pos == '\0')
	{
		return (1);
	}
	errno = 0;
	return (0);
}
