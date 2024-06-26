/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf_with_str_fmt.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:03:51 by shatan            #+#    #+#             */
/*   Updated: 2024/03/12 15:54:06 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

// fmt.precicion -> str len to print
// fmt.len -> remaining empty space to fill
// fmt.precicion = buflen if not specified to print entire string.
static void	preprocess_str_fmt(t_format *fmt, const char *buf)
{
	int	buflen;

	buflen = ft_strlen(buf);
	if (fmt->precicion < 0 || fmt->precicion > buflen)
		fmt->precicion = buflen;
	fmt->len -= fmt->precicion;
}

void	print_buf_str_fmt(t_format fmt, const char *buf, size_t *len)
{
	preprocess_str_fmt(&fmt, buf);
	if (fmt.left)
	{
		ft_printf_putnstr(buf, fmt.precicion, len);
		ft_printf_putnchar(' ', fmt.len, len);
	}
	else
	{
		ft_printf_putnchar(' ', fmt.len, len);
		ft_printf_putnstr(buf, fmt.precicion, len);
	}
}
