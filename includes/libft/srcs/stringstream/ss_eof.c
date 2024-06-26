/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_eof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:06:36 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 13:03:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// checks if stringstream had reached its end
bool	ss_eof(t_stringstream *ss)
{
	return (ss == NULL || ss->pos == NULL || *ss->pos == '\0');
}
