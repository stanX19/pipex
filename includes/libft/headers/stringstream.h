/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringstream.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:32:50 by shatan            #+#    #+#             */
/*   Updated: 2024/06/18 23:47:23 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGSTREAM_H
# define STRINGSTREAM_H
# include "common.h"
# include "ft_printf.h"
# include "constants.h"

typedef struct s_stringstream
{
	char		*str;
	char		*pos;
	char		*prev_pos;
}				t_stringstream;

t_stringstream	*ss_create(const char *str);
t_stringstream	*ss_create_use_provided(char *str);
t_stringstream	*ss_create_from_fd(int fd);
t_stringstream	*ss_copy(t_stringstream	*ss);
t_stringstream	*ss_setstr(t_stringstream *ss, const char *str);
char			*ss_getstr(t_stringstream *ss);
char			*ss_get_prev_str(t_stringstream *ss);
char			ss_peek(t_stringstream *ss);
t_stringstream	*ss_read_line(t_stringstream *ss, char **line,
					const char *seps);
t_stringstream	*ss_read_argv(t_stringstream *ss, char **line);
t_stringstream	*ss_read_char(t_stringstream *ss, char *cptr);
t_stringstream	*ss_read_int(t_stringstream *ss, int *val);
t_stringstream	*ss_read_long(t_stringstream *ss, long int *val);
t_stringstream	*ss_read_double(t_stringstream *ss, double *val);
t_stringstream	*ss_read_long_double(t_stringstream *ss, long double *val);
t_stringstream	*ss_skip_nchar(t_stringstream *ss, size_t n);
t_stringstream	*ss_skip_nword(t_stringstream *ss, size_t n,
					const char *seps);
t_stringstream	*ss_skip_to_charset(t_stringstream *ss, const char *charset);
t_stringstream	*ss_skip_to_numeric(t_stringstream *ss);
t_stringstream	*ss_skip_if(t_stringstream *ss, bool (*f)(int));
t_stringstream	*ss_skip_if_not(t_stringstream *ss, bool (*f)(int));
t_stringstream	*ss_append(t_stringstream *ss, const char *str);
t_stringstream	*ss_reset(t_stringstream *ss);
bool			ss_eof(t_stringstream *ss);
void			ss_destroy(t_stringstream *ss);

#endif // STRINGSTREAM