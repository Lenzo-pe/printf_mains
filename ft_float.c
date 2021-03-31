/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 02:56:42 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/31 00:19:03 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printright(t_speci *val, t_edit edit)
{
	ft_putnchar(' ', edit.spaces);
	ft_putsignal(val);
	ft_putnchar('0', edit.zeros);
	ft_putstr(val->str);
}

static void		ft_printleft(t_speci *val, t_edit edit)
{
	ft_putsignal(val);
	ft_putstr(val->str);
	ft_putnchar(' ', edit.spaces);
}

static void		ft_printfloat(t_speci *val, t_edit edit)
{
	if (!val->mode.left)
		ft_printright(val, edit);
	else
		ft_printleft(val, edit);
}

static void		ft_setnegative(t_speci *val)
{
	val->slen++;
	val->mode.negat = true;
	val->mode.space = false;
	val->mode.plus = false;
}

void		ft_float(t_speci *val, va_list ap)
{
	long double	n;
	t_edit		edit;

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
	if (n == INFINITY || n == NAN)
	{
		val->mode.zero = false;
		if (n == INFINITY)
			val->str = ft_strdup("inf");
		else if (n == NAN)
			val->str = ft_strdup("nan");
	}
	else
		val->str = ft_ftoa(n, val->preci);
	val->slen += ft_strlen(val->str);
	edit = ft_floatlab(val);
	ft_printfloat(val, edit);
	val->len += val->slen + edit.spaces + edit.zeros;
	ft_strdel(&val->str);
}
