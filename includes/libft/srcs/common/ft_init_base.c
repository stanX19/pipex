/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:56:52 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 16:56:52 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_base	ft_init_base(const char *base)
{
	t_base	ret;

	ret.str = base;
	ret.nbr = ft_strlen(base);
	return (ret);
}
