/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:42:54 by stan              #+#    #+#             */
/*   Updated: 2024/06/15 11:44:06 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_endswith(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	if (!str || !suffix)
	{
		return (false);
	}
	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > str_len)
	{
		return (false);
	}
	return (ft_strequ(str + str_len - suffix_len, suffix));
}
