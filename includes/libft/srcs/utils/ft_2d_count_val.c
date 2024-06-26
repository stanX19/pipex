/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_count_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:39:06 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 15:33:15 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_2d_count_val(char *const*map, int width, int height, char target)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] == target)
				++count;
			++i;
		}
		++j;
	}
	return (count);
}

int	ft_2d_count_charset(char *const*map, int width, int height,
	const char *charset)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (ft_strchr(charset, map[j][i]))
				++count;
			++i;
		}
		++j;
	}
	return (count);
}
