#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>
#include <math.h>
#include <stddef.h>
#include <string.h>



int		main(void)
{
	int i, z;
	double d = 4456.0123444555;
	i = printf(" %10e ", 0.0 / 0);
	printf("\n");
	z = ft_printf(" %10e ", 0.0 / 0);
	printf("\n");
	printf(" %d::%d ", i, z);
	return (0);
}
