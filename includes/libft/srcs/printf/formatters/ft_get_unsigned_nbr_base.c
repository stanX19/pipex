/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unsigned_nbr_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:22:42 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 21:12:22 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	recur(long long unsigned int val, char *buf, size_t *idx,
		t_base base)
{
	if (val >= base.nbr)
		recur(val / base.nbr, buf, idx, base);
	buf[(*idx)++] = base.str[val % base.nbr];
}

size_t	get_unsigned_nbr_base(long long unsigned int val,
		char *buf, const char *basestr)
{
	size_t	idx;
	t_base	base;

	base.nbr = ft_strlen(basestr);
	base.str = basestr;
	idx = 0;
	recur(val, buf, &idx, base);
	buf[idx] = 0;
	return (idx);
}
