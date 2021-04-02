/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:43:45 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/04/02 17:01:51 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# define FT_ERROR -1

typedef struct	s_float
{
	bool		infinity;
	bool		nanumber;
}				t_float;

typedef struct	s_editor
{
	int			strlen;
	int			spaces;
	int			zeros;
	char		tspaces;
}				t_edit;

typedef struct	s_modes
{
	bool		zero;
	bool		left;
	bool		width;
	bool		preci;
	bool		negat;
	bool		plus;
	bool		space;
}				t_modes;

typedef struct	s_utilities
{
	int			skip;
	int			error;
	char		*temp;
}				t_utils;

typedef struct	s_specifiers
{
	int			c;
	int			len;
	int			width;
	int			preci;
	int			slen;
	char		*str;
	t_modes		mode;
	t_utils		util;
}				t_speci;

int				ft_printf(const char *format, ...);

int				ft_whatisnext(const char *form, va_list ap, t_speci *list);
void			settings(const char *form, t_speci *val, va_list ap);

void			ft_integer(t_speci *val, va_list ap);
void			ft_unsignedint(t_speci *val, va_list ap);
void			ft_hexadecimal(t_speci *val, va_list ap);
void			ft_pointer(t_speci *val, va_list ap);
void			ft_ascii(t_speci *val, va_list ap);
void			ft_string(t_speci *val, va_list ap);
void			ft_number(t_speci *val, va_list ap);
void			ft_float(t_speci *val, va_list ap);
void			ft_floatexp(t_speci *val, va_list ap);

int				ft_nan(long double n);
int				ft_inf(long double n);
long long		ft_abs(long long n);
long double		ft_fabs(long double n);
char			*ft_exx(int e);
int				ft_exp(long double n);
long double		ft_powe(long double n, int e);

void			ft_putnstr(char *str, size_t n);
void			ft_putnchar(char c, size_t n);
void			ft_putchar(unsigned char c);
void			ft_putstr(char *str);
void			ft_putsignal(t_speci *val);

char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *str);
void			ft_strdel(char **str);
char			*ft_joindeld(char *s1, char const *s2);
char			*ft_joindel(char *s1, char *s2);

void			ft_strrev(char *str);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t maxlen);
size_t			ft_nbrlen(long long n);
size_t			xnbrlen(unsigned long long n);

t_edit			ft_numberlab(t_speci *val);
t_edit			ft_asciilab(t_speci *val);
t_edit			ft_floatlab(t_speci *val);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isspace(int c);
int				ft_islower(int c);
int				ft_isupper(int c);

int				ft_islegal(int c);
int				ft_isflag(int c);
int				ft_isspecifier(int c);

int				ft_atoi(const char *nptr);
char			*ft_xtoa(unsigned long long n, int c);
char			*ft_itoa(long long n);
char			*ft_ftoa(long double n, size_t len);
char			*ft_iwtoa(long long n, size_t w);

#endif
