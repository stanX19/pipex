/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:31:24 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 19:29:50 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_percent(t_format format, va_list *argv, size_t *idx)
{
	(void)argv;
	format.precicion = -1;
	format.prefix = "";
	if (IS_APPLE)
		print_buf_int_fmt(format, "%", idx);
	else
		ft_printf_putchar('%', idx);
}
