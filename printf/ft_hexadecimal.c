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
int ft_hexadecimal_u(unsigned int number, int max)
{
	unsigned int	a;
	int				b;
	int				n;

	n = 0;
	a = number / 16;
	b = number % 16;
	if (a > 0)
		n += ft_hexadecimal_u(a,max);
	n += write_hex(b,max);
	return (n);
}
int ft_hexadecimal(int number, int max)
{
	unsigned int	a;
	int				b;
	unsigned int 	u_number;
	int				n;

	if(number < 0)
		u_number = MAX_UINT + (number + 1);
	else
		u_number = number;
	a = u_number / 16;
	b = u_number % 16;
	n = 0;
	if (a > 0 && number >= 0)
		n += ft_hexadecimal(a,max);
	else if (a > 0 && number < 0)
		n += ft_hexadecimal_u(a,max);
	n += write_hex(b,max);
	return (n);
}
