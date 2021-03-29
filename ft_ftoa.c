/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:16:33 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/29 18:01:12 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long double ft_round(long double n)
{
	long double right;
	long unsigned left;

	left = (unsigned)n;
	right = n - (double)left;

	if (right > 0.5)
		n += 0.5;
	else if (right == 0.5)
	{
		if ((left % 2))
			n += 0.5;
	}
	return((unsigned long)n);
}


char		*ft_ftoa(long double n, size_t len)
{
	uint64_t	left;
	uint64_t	right;
	char		*str;

	if (!len)
		n = ft_round(n);
	left = (unsigned)n;
	n = n - (double)left;
	str = ft_itoa(left);
	if (len)
	{
		str = ft_joindel(str, ".");
		while(len--)
		{
			n *= 10;
			right = n;
			right %= 10;
			str = ft_joindelall(str, ft_itoa(right));
		}
	}
	return (str);
}
