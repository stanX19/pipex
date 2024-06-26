/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:33:22 by shatan            #+#    #+#             */
/*   Updated: 2024/06/17 17:41:55 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2
{
	int					x;
	int					y;
}						t_vec2;

t_vec2					vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2					vec2_sub(t_vec2 v1, t_vec2 v2);
double					vec2_hypot(t_vec2 v);

#endif  //VECTOR
