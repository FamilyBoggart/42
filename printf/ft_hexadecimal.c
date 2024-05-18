#include "ft_printf.h"

int write_hex(int b,int max)
{
	char	*hex;
	int		n;

	n = 0;
	if (!max)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	n += ft_putchar(hex[b]);

	return (n);
}
int ft_hexadecimal(int number, int max)
{
	int	a;
	int	b;

	a = number / 16;
	b = number % 16;
	if (a > 0)
		ft_hexadecimal(a,max);
	return (write_hex(b,max));
}
