/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:10:38 by stan              #+#    #+#             */
/*   Updated: 2024/04/19 10:17:34 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_val(const char *str, int sign)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10) + (str[i++] - '0');
	}
	return (sign * ret);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		++str;
	return (get_val(str, sign));
}
