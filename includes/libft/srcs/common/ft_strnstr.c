/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:58:14 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 20:14:49 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	idx = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)haystack);
	while (idx + needle_len <= len && haystack[idx])
	{
		if (ft_strncmp(haystack + idx, needle, needle_len) == 0)
			return ((char *)haystack + idx);
		++idx;
	}
	return (0);
}
