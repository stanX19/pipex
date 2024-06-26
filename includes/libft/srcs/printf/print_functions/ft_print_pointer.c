/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:42 by stan              #+#    #+#             */
/*   Updated: 2024/04/20 12:16:44 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_pointer(t_format format, va_list *argv, size_t *len)
{
	unsigned long long int	val;
	char					buf[21];

	val = va_arg(*argv, unsigned long int);
	if (val != 0)
	{
		format.prefix = "0x";
		get_unsigned_nbr_base(val, buf, "0123456789abcdef");
	}
	else if (IS_APPLE)
		ft_strlcpy(buf, "0x0", sizeof(buf));
	else
		ft_strlcpy(buf, "(nil)", sizeof(buf));
	print_buf_int_fmt(format, buf, len);
}
