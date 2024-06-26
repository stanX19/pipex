/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:45:28 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 18:54:22 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_strlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		++len;
	while (nb)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*buf;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_strlen(n);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (0);
	if (n == 0)
		buf[0] = '0';
	buf[len--] = '\0';
	if (n < 0)
	{
		n *= -1;
		buf[0] = '-';
	}
	while (n != 0)
	{
		buf[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (buf);
}
