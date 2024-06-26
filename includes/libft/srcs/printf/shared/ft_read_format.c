/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:40:08 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:40:08 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

// format.precicion < 0 means undefined
static void	init_format(t_format *format)
{
	format->len = 0;
	format->precicion = -1;
	format->prefix = "";
	format->left = 0;
	format->hash = 0;
	format->zero = 0;
}

static void	match_flags(t_format *format, const char *format_str, size_t *idx)
{
	while (format_str[++(*idx)])
	{
		if (format_str[(*idx)] == '+')
			format->prefix = "+";
		else if (format_str[(*idx)] == ' ')
			format->prefix = " ";
		else if (format_str[(*idx)] == '#')
			format->hash = 1;
		else if (format_str[(*idx)] == '-')
			format->left = 1;
		else if (format_str[(*idx)] == '0')
			format->zero = 1;
		else
			return ;
	}
}

static int	read_int(const char *buf, size_t *idx)
{
	int	val;
	int	sign;

	val = 0;
	sign = 1;
	if (buf[*idx] == '-')
	{
		(*idx)++;
		sign = -1;
	}
	while (buf[*idx] && ft_isdigit(buf[*idx]))
	{
		val = val * 10 + buf[(*idx)++] - '0';
	}
	return (val * sign);
}

static void	read_if_asteric(const char *format_str, int *val,
	size_t *idx, va_list *argv)
{
	if (format_str[*idx] == '*')
	{
		*val = va_arg(*argv, int);
		(*idx)++;
	}
}

t_format	read_format(const char *format_str, va_list *argv, size_t *idx)
{
	t_format	format;

	init_format(&format);
	*idx = -1;
	match_flags(&format, format_str, idx);
	format.len = read_int(format_str, idx);
	read_if_asteric(format_str, &format.len, idx, argv);
	if (format.len < 0)
	{
		format.left = 1;
		format.len = -format.len;
	}
	if (format_str[*idx] && format_str[*idx] == '.')
	{
		(*idx)++;
		format.precicion = read_int(format_str, idx);
		read_if_asteric(format_str, &format.precicion, idx, argv);
	}
	format.func = match_function(format_str + *idx, idx);
	return (format);
}
