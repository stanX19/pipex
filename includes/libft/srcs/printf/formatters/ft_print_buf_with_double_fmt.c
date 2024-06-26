/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf_with_double_fmt.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:03:51 by shatan            #+#    #+#             */
/*   Updated: 2024/03/13 15:01:04 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

// fmt.precicion -> remaining zeros (after buffer) to fill in
// fmt.len -> remaining empty space to fill
// fmt.precicion is already defined by `get_double` function
// fmt.precicion cannot be negative
static void	preprocess_double_fmt(t_format *fmt, const char *buf)
{
	fmt->precicion *= (fmt->precicion > 0);
	fmt->len -= fmt->precicion + ft_strlen(buf) + ft_strlen(fmt->prefix);
}

void	print_buf_double_fmt(t_format fmt, const char *buf, size_t *len)
{
	preprocess_double_fmt(&fmt, buf);
	if (fmt.left)
	{
		ft_printf_putstr(fmt.prefix, len);
		ft_printf_putstr(buf, len);
		ft_printf_putnchar('0', fmt.precicion, len);
		ft_printf_putnchar(' ', fmt.len, len);
	}
	else
	{
		ft_printf_putnchar(' ', fmt.len, len);
		ft_printf_putstr(fmt.prefix, len);
		ft_printf_putstr(buf, len);
		ft_printf_putnchar('0', fmt.precicion, len);
	}
}
