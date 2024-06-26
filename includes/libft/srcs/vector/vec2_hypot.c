/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_hypot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:36:37 by shatan            #+#    #+#             */
/*   Updated: 2024/06/17 18:40:48 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// safe hypot by using r as ratio, derived from the normal hypot
double	vec2_hypot(t_vec2 v)
{
	int		min;
	int		max;
	double	r;

	v.x = ft_abs(v.x);
	v.y = ft_abs(v.y);
	max = ft_max(v.x, v.y);
	min = ft_min(v.x, v.y);
	r = (double)min / max;
	return (max * ft_sqrt(1 + r * r));
}
