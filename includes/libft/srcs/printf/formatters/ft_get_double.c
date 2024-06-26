/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:31:45 by stan              #+#    #+#             */
/*   Updated: 2024/03/12 15:31:45 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline void	add_decimal(int *idx, char *buf, long double val,
		int *decimal)
{
	unsigned long long int	store;
	unsigned long long int	place;
	int						i;

	i = -1;
	place = 10;
	while (++i < *decimal && i < 18)
		place *= 10;
	store = (val - ((long long unsigned int)val)) * place;
	if (store % 10 > 4)
		store += 10;
	buf[(*idx)++] = '.';
	while ((*decimal)-- > 0 && place > 9)
	{
		place /= 10;
		buf[(*idx)++] = (store / place) % 10 + 48;
	}
}

static inline void	write_double(int *idx, char *buf, long double val,
		int *decimal)
{
	long long unsigned int	place;
	long long unsigned int	digits;

	place = 1;
	digits = (long long unsigned int)val;
	if (!*decimal)
		digits += (((val - (int)val) * 10) >= 5);
	while (place * 10 < digits)
		place *= 10;
	while (place > 0)
	{
		buf[(*idx)++] = ((int)digits / place) % 10 + 48;
		place /= 10;
	}
	if (*decimal)
		add_decimal(idx, buf, val, decimal);
}

size_t	get_double(t_format *fmt, long double val, char *buf)
{
	int	idx;

	idx = 0;
	if (val < 0)
	{
		val = -val;
		fmt->prefix = "-";
	}
	else if (fmt->prefix[0])
		buf[idx++] = fmt->prefix[0];
	if (fmt->precicion < 0)
		fmt->precicion = 6;
	write_double(&idx, buf, val, &fmt->precicion);
	buf[idx] = 0;
	return (idx);
}
