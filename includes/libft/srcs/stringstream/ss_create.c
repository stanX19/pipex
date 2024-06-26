/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:46:32 by shatan            #+#    #+#             */
/*   Updated: 2024/05/04 12:25:58 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// creates stringstring from str, the stored version is a copy from strdup
t_stringstream	*ss_create(const char *str)
{
	t_stringstream	*ss;

	ss = (t_stringstream *)malloc(sizeof(t_stringstream));
	if (ss == NULL)
		return (NULL);
	ss->str = ft_strdup(str);
	if (!ss->str)
	{
		free(ss);
		return (NULL);
	}
	ss->pos = ss->str;
	ss->prev_pos = NULL;
	return (ss);
}

t_stringstream	*ss_create_use_provided(char *str)
{
	t_stringstream	*ss;

	ss = (t_stringstream *)malloc(sizeof(t_stringstream));
	if (ss == NULL)
		return (NULL);
	ss->str = str;
	if (!ss->str)
	{
		free(ss);
		return (NULL);
	}
	ss->pos = ss->str;
	ss->prev_pos = NULL;
	return (ss);
}
