/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:39:33 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:39:33 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_putchar(char c, size_t *len)
{
	(*len) += write(ft_printf_fd_get(), &c, 1);
}

void	ft_printf_putnchar(char c, int n, size_t *len)
{
	while (n-- > 0)
		*len += write(ft_printf_fd_get(), &c, 1);
}
