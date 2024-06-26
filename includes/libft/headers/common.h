/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:46:36 by shatan            #+#    #+#             */
/*   Updated: 2024/06/26 14:05:56 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "common.h"

typedef struct s_base
{
	size_t		nbr;
	const char	*str;
}				t_base;

void			ft_bzero(void *s, size_t n);
bool			ft_isalpha(int c);
bool			ft_isdigit(int c);
bool			ft_isalnum(int c);
bool			ft_isascii(int c);
bool			ft_isprint(int c);
bool			ft_isspace(int c);
bool			ft_isspace_or_null(int c);
bool			ft_isnumeric(const char *str);
void			*ft_memset(void *str, int c, size_t n);
size_t			ft_strlen(const char *s);
int				ft_toupper(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
bool			ft_endswith(const char *str, const char *suffix);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_tolower(int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
bool			ft_strequ(const char *s1, const char *s2);
bool			ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strpbrk(const char *s, const char *charset);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
bool			ft_mem_is_zero(const void *p, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t size, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(size_t n, ...);
char			*ft_itoa(int n);
long			ft_abs(long a);
long			ft_max(long a, long b);
long			ft_min(long a, long b);
double			ft_sqrt(double number);
long			ft_sign(long nb);
long			ft_pow(long nu, long exp);
long			ft_magnitude_shift(long nb, long magnitude);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
bool			ft_path_exists(const char *path);
char			**ft_split(char const *s, char c);
void			ft_swap(void *a, void *b, size_t size);
void			ft_int_swap(int *a, int *b);
void			ft_char_swap(char *a, char *b);
char			*ft_strrev(char *s);
char			*ft_strnrev(char *s, size_t n);
void			ft_tokens_free(char **tokens);
size_t			ft_tokens_len(char *const*tokens);
char			*ft_tokens_join(char *const*tokens, size_t len,
					const char *sep);
char			**ft_str_to_argv(const char *str, int *argc);
t_base			ft_init_base(const char *base);
long			ft_strtol(const char *_str, char **endptr, const char *_base);
long double		ft_strtold(const char *nptr, char **endptr);

void			**ft_calloc_2d(size_t height, size_t width, size_t pointer_size,
					size_t element_size);
void			ft_free_2d(void **ptr, size_t len);
void			ft_free_ptr_arr(void **arr, size_t len,
					void (*free_func)(void *));
int				ft_str_count_val(const char *str, char target);
int				ft_str_count_charset(const char *str, const char *charset);
int				ft_2d_count_val(char *const*map, int width, int height,
					char target);
int				ft_2d_count_charset(char *const*map, int width, int height,
					const char *charset);
char			**ft_str_to_argv(const char *str, int *argc);
void			ft_str_append(char **strptr, const char *add);
void			ft_strnappend(char **strptr, size_t n, ...);
char			*ft_str_insert(char **strptr, char *inserted, size_t idx);

#endif // COMMON
