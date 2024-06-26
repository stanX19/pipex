/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:25:19 by stan              #+#    #+#             */
/*   Updated: 2024/05/04 12:25:30 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// creates a copy with same string and position
t_stringstream	*ss_copy(t_stringstream *ss)
{
	t_stringstream	*copy;

	copy = (t_stringstream *)malloc(sizeof(t_stringstream));
	if (copy == NULL)
		return (NULL);
	copy->str = ft_strdup(ss->str);
	if (!copy->str)
	{
		free(copy);
		return (NULL);
	}
	copy->pos = copy->str + (ss->pos - ss->str);
	copy->prev_pos = copy->pos + (ss->prev_pos - ss->str);
	return (copy);
}
