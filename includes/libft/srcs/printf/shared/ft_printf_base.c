/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:16:43 by stan              #+#    #+#             */
/*   Updated: 2024/05/29 13:17:45 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	print_format(char *format_str, va_list *argv, size_t *len)
{
	size_t		idx;
	t_format	format;

	format = read_format(format_str, argv, &idx);
	if (format.func)
		format.func(format, argv, len);
	return (idx);
}

size_t	ft_printf_base(int fd, const char *str, va_list *argv)
{
	size_t	i;
	size_t	len;

	ft_printf_fd_set(fd);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += print_format((char *)(str + i + 1), argv, &len);
		else
			ft_printf_putchar(str[i], &len);
		i++;
	}
	return (len);
}
