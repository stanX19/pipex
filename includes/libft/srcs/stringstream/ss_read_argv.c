/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_read_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:50:48 by shatan            #+#    #+#             */
/*   Updated: 2024/06/26 13:47:36 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

static char	*find_start_of_line(char *newpos)
{
	while (*newpos != '\0' && ft_strchr(WHITESPACE, *newpos))
		newpos++;
	return (newpos);
}

// inside of '', no escape
// inside of "", escape \ and " only, 
// outside of quote, escape everything
static char	get_word_helper(char **pos, int i, char *quote)
{
	char	c;

	c = (*pos)[i];
	if (c == '\\' && *quote == '\'' && (*pos)[i + 1] == '\'')
		return ('\'');
	else if (c == '\\' && *quote == '"' && ft_strchr("\"\\", (*pos)[i + 1]))
		return ((++(*pos))[i]);
	else if (c == '\\' && !*quote)
		return ((++(*pos))[i]);
	else if (!*quote && (c == '"' || c == '\''))
		*quote = c;
	else if (*quote && c == *quote)
		*quote = '\0';
	else
		return ((*pos)[i]);
	return ('\0');
}

static char	*find_end_of_line(char *newpos, int *strlen)
{
	char	quote;
	char	c;

	*strlen = 0;
	quote = '\0';
	while (*newpos != '\0' && (!ft_strchr(WHITESPACE, *newpos)
			|| quote != '\0'))
	{
		c = get_word_helper(&newpos, 0, &quote);
		if (c)
			++(*strlen);
		++newpos;
	}
	if (quote)
		errno = EINVAL;
	return (newpos);
}

static char	*get_word(char *pos, size_t strlen)
{
	char	*ret;
	int		i;
	char	quote;
	char	c;

	ret = (char *)ft_calloc(sizeof(char), strlen + 1);
	if (!ret)
		return (NULL);
	quote = '\0';
	i = 0;
	while (pos[i] != '\0' && (!ft_strchr(WHITESPACE, pos[i]) || quote != '\0'))
	{
		c = get_word_helper(&pos, i, &quote);
		if (c)
			ret[i++] = c;
		else
			++pos;
	}
	return (ret);
}

// ss: stringstream object, line: pointer to str, seps: seperating charset
// success	:	return ss,		line is malloced str,	errno = 0
// eof		:	return NULL,	line is NULL,			errno = 0
// unclosed quote: return NULL,	line is NULL,			errno = EINVAL
t_stringstream	*ss_read_argv(t_stringstream *ss, char **line)
{
	char	*start;
	char	*newpos;
	int		strlen;

	if (line != NULL)
		*line = NULL;
	if (ss_read_precheck(ss))
		return (NULL);
	start = find_start_of_line(ss->pos);
	if (*start == '\0')
		return (NULL);
	newpos = find_end_of_line(start, &strlen);
	if (errno)
		return (NULL);
	if (line != NULL)
		*line = get_word(start, strlen);
	return (ss_read_get_return(ss, newpos));
}
