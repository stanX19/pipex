/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:29:57 by stan              #+#    #+#             */
/*   Updated: 2024/03/11 13:40:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_unsigned(t_format format, va_list *argv, size_t *len)
{
	unsigned int	val;
	char			buf[25];

	val = va_arg(*argv, unsigned int);
	get_unsigned_nbr_base(val, buf, "0123456789");
	print_buf_int_fmt(format, buf, len);
}
