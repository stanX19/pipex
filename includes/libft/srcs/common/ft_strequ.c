/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:22:39 by shatan            #+#    #+#             */
/*   Updated: 2024/05/04 12:25:50 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strequ(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}

bool	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	return (ft_strncmp(s1, s2, n) == 0);
}
