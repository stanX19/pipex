/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:20:08 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 20:15:58 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	if (!dst && !src && n)
		return (0);
	dest = (char *)dst;
	source = (char *)src;
	i = -1;
	while (++i < n)
		dest[i] = source[i];
	return (dest);
}
