/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:37:48 by stan              #+#    #+#             */
/*   Updated: 2024/04/12 23:20:12 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char delim)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] != delim && (idx == 0 || str[idx - 1] == delim))
		{
			++count;
		}
		++idx;
	}
	return (count);
}

static int	fill_ret(char **ret, char const *str, char c)
{
	int	start_idx;
	int	idx;
	int	ret_idx;

	idx = 0;
	ret_idx = 0;
	start_idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			start_idx = idx + 1;
		else if (!str[idx + 1] || str[idx + 1] == c)
		{
			ret[ret_idx] = ft_substr(str, start_idx, idx + 1 - start_idx);
			if (ret[ret_idx++] == 0)
				return (-1);
		}
		idx++;
	}
	ret[ret_idx] = 0;
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;

	if (!str)
		return (NULL);
	ret = malloc(sizeof(char *) * (word_count(str, c) + 1));
	if (!ret)
		return (NULL);
	if (fill_ret(ret, str, c))
	{
		ft_tokens_free(ret);
		ret = NULL;
	}
	return (ret);
}
