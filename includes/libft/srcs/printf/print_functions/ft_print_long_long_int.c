/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_long_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:34:15 by stan              #+#    #+#             */
/*   Updated: 2024/03/11 13:40:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_long_long_int(t_format format, va_list *argv, size_t *len)
{
	long long int	val;
	char			buf[50];

	val = va_arg(*argv, long long int);
	get_int(&format, val, buf);
	print_buf_int_fmt(format, buf, len);
}
