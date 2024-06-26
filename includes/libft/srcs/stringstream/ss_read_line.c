/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:50:48 by shatan            #+#    #+#             */
/*   Updated: 2024/06/18 18:00:36 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

static char	*find_start_of_line(char *newpos, const char *seps)
{
	while (*newpos != '\0' && ft_strchr(seps, *newpos))
		newpos++;
	return (newpos);
}

static char	*find_end_of_line(char *newpos, const char *seps)
{
	while (*newpos != '\0' && !ft_strchr(seps, *newpos))
		newpos++;
	return (newpos);
}

// ss: stringstream object, line: pointer to str, seps: seperating charset
// success	:	return ss,		line is malloced str,	errno = 0
// eof		:	return NULL,	line is NULL,			errno = 0
t_stringstream	*ss_read_line(t_stringstream *ss, char **line, const char *seps)
{
	char	*start;
	char	*newpos;

	if (line != NULL)
		*line = NULL;
	if (ss_read_precheck(ss))
		return (NULL);
	start = find_start_of_line(ss->pos, seps);
	if (*start == '\0')
		return (NULL);
	newpos = find_end_of_line(start + 1, seps);
	if (line != NULL)
		*line = ft_strndup(start, newpos - start);
	return (ss_read_get_return(ss, newpos));
}
