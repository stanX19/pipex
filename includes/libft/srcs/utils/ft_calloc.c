/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:34:49 by stan              #+#    #+#             */
/*   Updated: 2024/04/23 14:16:06 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size, size_t n)
{
	void	*a;

	if (size && n >= INT_MAX / size)
		return (NULL);
	size *= n;
	size += (size == 0);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (size));
	return (a);
}
