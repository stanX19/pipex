/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:57:47 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 20:15:19 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + 1;
	ret = malloc(sizeof(char) * dstsize);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, dstsize);
	return (ret);
}
