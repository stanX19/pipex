/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:58:54 by shatan            #+#    #+#             */
/*   Updated: 2024/03/07 14:58:54 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	ft_printf(const char *str, ...)
{
	size_t	len;
	va_list	argv;

	va_start(argv, str);
	len = ft_printf_base(1, str, &argv);
	va_end(argv);
	return (len);
}
