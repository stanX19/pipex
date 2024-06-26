/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:38:30 by stan              #+#    #+#             */
/*   Updated: 2024/03/10 12:57:41 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_char(t_format format, va_list *argv, size_t *len)
{
	char	c;

	c = va_arg(*argv, int);
	format.len -= 1;
	if (format.zero)
	{
		ft_printf_putnchar('0', format.len, len);
		ft_printf_putchar(c, len);
	}
	else if (format.left)
	{
		ft_printf_putchar(c, len);
		ft_printf_putnchar(' ', format.len, len);
	}
	else
	{
		ft_printf_putnchar(' ', format.len, len);
		ft_printf_putchar(c, len);
	}
}
