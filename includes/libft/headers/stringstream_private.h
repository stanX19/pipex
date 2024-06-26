/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringstream_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:00:14 by shatan            #+#    #+#             */
/*   Updated: 2024/04/29 19:09:55 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGSTREAM_PRIVATE_H
# define STRINGSTREAM_PRIVATE_H
# include "common.h"
# include "ft_printf.h"
# include "stringstream.h"

t_stringstream	*ss_update_pos(t_stringstream *ss, char *newpos);
int				ss_read_precheck(t_stringstream *ss);
t_stringstream	*ss_read_get_return(t_stringstream *ss, char *newpos);

#endif  //STRINGSTREAM_PRIVATE