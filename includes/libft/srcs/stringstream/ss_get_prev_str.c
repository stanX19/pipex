/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_get_prev_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:54:05 by shatan            #+#    #+#             */
/*   Updated: 2024/05/04 12:26:03 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

char	*ss_get_prev_str(t_stringstream *ss)
{
	if (!ss || !ss->prev_pos || !ss->pos)
		return (ft_calloc(sizeof(char), 1));
	return (ft_strndup(ss->prev_pos, ss->pos - ss->prev_pos));
}
