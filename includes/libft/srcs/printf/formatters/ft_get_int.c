/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:25:17 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 21:09:07 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	get_int(t_format *format, long long int nbr, char *buf)
{
	unsigned long long int	val;

	val = nbr;
	if (nbr < 0)
	{
		format->prefix = "-";
		val = -nbr;
	}
	return (get_unsigned_nbr_base(val, buf, "0123456789"));
}
