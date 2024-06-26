/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:02:45 by shatan            #+#    #+#             */
/*   Updated: 2024/06/26 15:55:58 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_insert(char **strptr, char *inserted, size_t idx)
{
	char	*new_str;
	int		orig_len;
	int		ins_len;
	int		new_len;

	if (strptr == NULL || *strptr == NULL || inserted == NULL
		|| idx > ft_strlen(*strptr))
	{
		return (NULL);
	}
	orig_len = ft_strlen(*strptr);
	ins_len = ft_strlen(inserted);
	new_len = orig_len + ins_len;
	new_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}
	ft_strncpy(new_str, *strptr, idx);
	ft_strcpy(new_str + idx, inserted);
	ft_strcpy(new_str + idx + ins_len, *strptr + idx);
	free(*strptr);
	*strptr = new_str;
	return (new_str);
}
