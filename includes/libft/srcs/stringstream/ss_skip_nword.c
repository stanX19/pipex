/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_skip_nword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:54:31 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 19:22:37 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// skips `n` number of words seperated by characters specified in `seps` charset
t_stringstream	*ss_skip_nword(t_stringstream *ss, size_t n,
		const char *seps)
{
	char	*original_pos;
	size_t	i;

	if (ss == NULL || ss->pos == NULL)
		return (NULL);
	original_pos = ss->pos;
	i = 0;
	while (i < n && ss_read_line(ss, NULL, seps))
	{
		i++;
	}
	ss->prev_pos = original_pos;
	return (ss);
}
