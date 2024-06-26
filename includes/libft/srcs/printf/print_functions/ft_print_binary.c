/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:38:42 by stan              #+#    #+#             */
/*   Updated: 2024/03/11 13:40:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_binary(t_format format, va_list *argv, size_t *len)
{
	unsigned long long int	val;
	char					buf[513];

	val = va_arg(*argv, long long unsigned int);
	format.prefix = "0b";
	get_unsigned_nbr_base(val, buf, "01");
	print_buf_int_fmt(format, buf, len);
}
