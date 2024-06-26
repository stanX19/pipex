/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:39:12 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 22:28:43 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d(void **ptr, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (ptr[idx])
			free(ptr[idx]);
		++idx;
	}
	free(ptr);
}
