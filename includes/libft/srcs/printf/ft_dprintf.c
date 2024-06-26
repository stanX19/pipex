/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:17:17 by shatan            #+#    #+#             */
/*   Updated: 2024/05/29 13:17:17 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	ft_dprintf(int fd, const char *str, ...)
{
	size_t	len;
	va_list	argv;

	va_start(argv, str);
	len = ft_printf_base(fd, str, &argv);
	va_end(argv);
	return (len);
}
