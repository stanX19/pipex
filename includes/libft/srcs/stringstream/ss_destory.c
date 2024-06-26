/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_destory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:10:00 by stan              #+#    #+#             */
/*   Updated: 2024/04/29 13:03:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// frees the memory stored in stringstream
void	ss_destroy(t_stringstream *ss)
{
	if (ss == NULL)
		return ;
	if (ss->str != NULL)
		free(ss->str);
	free(ss);
}
