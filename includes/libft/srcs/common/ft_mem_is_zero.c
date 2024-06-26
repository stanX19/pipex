/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_is_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:44:58 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 01:04:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_mem_is_zero(const void *p, size_t n)
{
	unsigned char	*s;

	if (n == 0)
		return (true);
	s = (unsigned char *)p;
	while (--n && *s == '\0')
		++s;
	return (*s == '\0');
}
