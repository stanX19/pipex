/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:17 by stan              #+#    #+#             */
/*   Updated: 2024/03/11 13:41:12 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_str(t_format format, va_list *argv, size_t *len)
{
	char	*src;

	src = va_arg(*argv, char *);
	if (!src)
		src = "(null)";
	print_buf_str_fmt(format, src, len);
}
