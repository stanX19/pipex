/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:01:13 by shatan            #+#    #+#             */
/*   Updated: 2024/04/20 14:35:16 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	get_digit(char **str, int *digit)
{
	if (ft_isdigit(**str))
	{
		*digit = (**str - '0');
		(*str)++;
		return (true);
	}
	return (false);
}

long double	get_val(char **str, int sign)
{
	long double	ret;
	long double	counter;
	long double	decimals;
	int			digit;

	ret = 0;
	digit = -1;
	while (get_digit(str, &digit))
		ret = (ret * 10) + digit;
	if (**str == '.')
		(*str)++;
	counter = 1;
	decimals = 0;
	while (get_digit(str, &digit))
	{
		decimals = (decimals * 10) + digit;
		counter *= 10;
	}
	if (digit < 0)
		errno = EINVAL;
	return ((long double)sign * (ret + decimals / counter));
}

long double	ft_strtold(const char *nptr, char **endptr)
{
	int			sign;
	long double	ret;
	char		*str;

	sign = 1;
	str = (char *)nptr;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		++str;
	ret = get_val(&str, sign);
	if (endptr != NULL && errno == EINVAL)
		*endptr = (char *)nptr;
	else if (endptr != NULL)
		*endptr = str;
	return (ret);
}
