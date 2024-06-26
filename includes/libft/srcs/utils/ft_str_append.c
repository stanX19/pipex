/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:32:04 by stan              #+#    #+#             */
/*   Updated: 2024/06/23 15:11:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_append(char **ptr, const char *add)
{
	char	*new;

	if (add == NULL)
		return ;
	if (*ptr == NULL)
	{
		*ptr = ft_strdup(add);
		return ;
	}
	new = ft_strjoin(*ptr, add);
	free(*ptr);
	*ptr = new;
}
