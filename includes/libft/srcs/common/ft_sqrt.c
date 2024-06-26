/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:32:44 by shatan            #+#    #+#             */
/*   Updated: 2024/06/06 17:25:00 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// newton raphson method
double	ft_sqrt(double number)
{
	double	x;
	double	y;

	if (number < 0)
		return (-1);
	x = number;
	y = 0.5 * (x + number / x);
	while (y < x)
	{
		x = y;
		y = 0.5 * (x + number / x);
	}
	return (x);
}
