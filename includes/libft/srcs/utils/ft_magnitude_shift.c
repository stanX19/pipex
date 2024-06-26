/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magnitude_shift.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:42:52 by shatan            #+#    #+#             */
/*   Updated: 2024/04/30 16:00:34 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// shifts magnitude of an value, example:
// 10 shift up 3 -> 13
// -10 shift up 3 -> -13
long	ft_magnitude_shift(long nb, long magnitude)
{
	magnitude *= ft_sign(nb);
	return (nb + magnitude);
}
