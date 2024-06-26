/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:39:26 by stan              #+#    #+#             */
/*   Updated: 2024/05/25 18:12:23 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_putstr(const char *str, size_t *len)
{
	(*len) += write(ft_printf_fd_get(), str, ft_strlen(str));
}

void	ft_printf_putnstr(const char *str, int n, size_t *len)
{
	if (n <= 0)
		return ;
	(*len) += write(ft_printf_fd_get(), str, n);
}
