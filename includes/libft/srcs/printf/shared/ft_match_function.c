/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:41:58 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:41:58 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	format_cmp(const char *src, const char *target)
{
	int	i;

	i = 0;
	while (src[i] && target[i] && src[i] == target[i])
		i++;
	if (src[i] == 0)
		return (i);
	return (0);
}

static t_fmt_func	iterate(const t_pair *dict, const char *format_str,
		size_t *idx)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dict[i].key)
	{
		len = format_cmp(dict[i].key, format_str);
		if (len > 0)
		{
			*idx += len;
			return (dict[i].func);
		}
		i++;
	}
	if (IS_APPLE)
		return (NULL);
	(*idx) = 0;
	return (print_percent);
}

t_fmt_func	match_function(const char *format_str, size_t *idx)
{
	static t_pair	dict[] = {
	{"c", print_char},
	{"s", print_str},
	{"f", print_double},
	{"Lf", print_long_double},
	{"d", print_int},
	{"i", print_int},
	{"li", print_long_int},
	{"lli", print_long_int},
	{"u", print_unsigned},
	{"lu", print_long_unsigned},
	{"llu", print_long_long_unsigned},
	{"p", print_pointer},
	{"x", print_hex_lower},
	{"X", print_hex_upper},
	{"b", print_binary},
	{"%", print_percent},
	{NULL, NULL}
	};

	return (iterate(dict, format_str, idx));
}
