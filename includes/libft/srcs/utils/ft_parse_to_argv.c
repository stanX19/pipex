/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:53:57 by shatan            #+#    #+#             */
/*   Updated: 2024/06/23 15:13:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(t_stringstream *ss)
{
	int	len;

	len = 0;
	while (ss_read_argv(ss, NULL))
		len++;
	return (len);
}

char	**ft_str_to_argv(const char *str, int *argc)
{
	char			**ret;
	int				idx;
	int				len;
	t_stringstream	*ss;

	ss = ss_create(str);
	len = get_len(ss);
	ret = (char **)ft_calloc(sizeof(char *), len + 1);
	if (!ret)
		return (NULL);
	ss_reset(ss);
	idx = 0;
	while (ss_read_argv(ss, ret + idx))
		idx++;
	ss_destroy(ss);
	if (argc)
		*argc = len;
	return (ret);
}
