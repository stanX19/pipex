/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:23:26 by stan              #+#    #+#             */
/*   Updated: 2024/04/23 14:14:15 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	dstsize;

	dstsize = 0;
	while (dstsize < len + start && s[dstsize])
		dstsize++;
	if (dstsize < start)
		return ((char *)ft_calloc(sizeof(char), 1));
	dstsize = dstsize - start + 1;
	s = s + start;
	ret = malloc(sizeof(char) * dstsize);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, dstsize);
	return (ret);
}
