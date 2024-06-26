/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:37:25 by shatan            #+#    #+#             */
/*   Updated: 2024/06/04 13:38:38 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_calloc_2d(size_t height, size_t width, size_t pointer_size,
		size_t	element_size)
{
	void	**ret;
	size_t	i;

	ret = (void **)ft_calloc(pointer_size, height);
	if (ret == NULL)
	{
		return (NULL);
	}
	ft_memset(ret, 0, height * pointer_size);
	i = 0;
	while (i < height)
	{
		ret[i] = (void *)ft_calloc(element_size, width);
		if (!ret[i])
		{
			ft_free_2d(ret, height);
			return (0);
		}
		++i;
	}
	return (ret);
}
