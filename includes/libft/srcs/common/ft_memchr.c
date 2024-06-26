/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:30:43 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 19:30:59 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	if (!n)
		return (0);
	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == val)
			return (ptr);
		++ptr;
		++i;
	}
	return (0);
}
