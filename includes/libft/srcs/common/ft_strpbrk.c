/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:27:16 by shatan            #+#    #+#             */
/*   Updated: 2024/06/22 14:49:19 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	if (!s || !accept)
		return (NULL);
	while (*s)
	{
		if (ft_strchr(accept, *s))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
