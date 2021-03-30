/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:08:18 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/30 15:30:18 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printright(t_speci *val, t_edit edit, long double n)
{
	ft_putnchar(' ', edit.spaces);
	if (val->mode.negat)
		ft_putchar('-');
	else if (val->mode.space)
		ft_putchar(' ');
	else if (val->mode.plus)
		ft_putchar('+');
	ft_putnchar('0', edit.zeros);
	ft_putstr(val->str);
	if (n != INFINITY && n != NAN)
		ft_putstr("e+00");
}

static void		ft_printleft(t_speci *val, t_edit edit, long double n)
{
	if (val->mode.negat)
		ft_putchar('-');
	else if (val->mode.space)
		ft_putchar(' ');
	else if (val->mode.plus)
		ft_putchar('+');
	ft_putstr(val->str);
	if (n != INFINITY && n != NAN)
		ft_putstr("e+00");
	ft_putnchar(' ', edit.spaces);
}

static void		ft_printexponent(t_speci *val, t_edit edit, long double n)
{
	if (!val->mode.left)
		ft_printright(val, edit, n);
	else
		ft_printleft(val, edit, n);
}

static t_edit	ft_floatlab(t_speci *val)
{
	t_edit edit;

	edit.spaces = 0;
	edit.zeros = 0;
	if (val->mode.zero && !val->mode.left)
		edit.zeros = val->width - val->slen;
	else
		edit.spaces = val->width - val->slen;
	if (edit.spaces < 0)
		edit.spaces = 0;
	if (edit.zeros < 0)
		edit.zeros = 0;
	return (edit);
}

static void		ft_setnegative(t_speci *val)
{
	val->slen++;
	val->mode.negat = true;
	val->mode.space = false;
	val->mode.plus = false;
}

void		ft_exponent(t_speci *val, va_list ap)
{
	long double	n;
	t_edit		edit;

	val->slen += 4;
	n = va_arg(ap, double);
	if (!val->mode.preci)
		val->preci = 6;
	if (n < 0)
	{	
		ft_setnegative(val);
		n = ft_fabs(n);
	}
	if (val->mode.space || val->mode.plus)
		val->slen++;
	if (n == INFINITY)
	{
		val->str = ft_strdup("inf");
		val->mode.zero = false;
		val->slen -= 4;
	}
	else if (n == NAN)
	{
		val->str = ft_strdup("nan");
		val->mode.zero = false;
		val->slen -= 4;
	}
	else
		val->str = ft_ftoa(n, val->preci);
	val->slen += ft_strlen(val->str);
	edit = ft_floatlab(val);
	ft_printexponent(val, edit, n);
	val->len += val->slen + edit.spaces + edit.zeros;
	ft_strdel(&val->str);
}