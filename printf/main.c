#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
	int f,p;

	f = ft_printf("Characters: %c %c %c %c %c\n",'a',99, 125+1, -1, 200);
	p=     printf("Characters: %c %c %c %c %c\n",'a',99, 125+1, -1, 200);
	if(f == p)
		ft_printf("OK\n");

	f = ft_printf("String: %s\n","Hola Mundo");
	p=     printf("String: %s\n","Hola Mundo");
	if(f == p)
		ft_printf("OK\n");

	f = ft_printf("Integer: %i %i %i %i\n",9, 100+20+3, -5, 0);
	p=     printf("Integer: %i %i %i %i\n",9, 100+20+3, -5, 0);
	if(f == p)
		ft_printf("OK\n");

	f = ft_printf("Decimal: %d %d %d %d\n",9, 100+20+3, -5, 0);
	p=     printf("Decimal: %d %d %d %d\n",9, 100+20+3, -5, 0);
	if(f == p)
		ft_printf("OK\n");

	f = ft_printf("Unsigned int: %u %u %u %u %u\n",9, 100+20+3, -5, 0, 2147483647);
	p=     printf("Unsigned int: %u %u %u %u %u\n",9, 100+20+3, -5, 0, 2147483647);
	if(f == p)
		ft_printf("OK\n");


	f = ft_printf("Hexadecimal: %x %x %x %x\n",0, -1, 16, 2147483647);
	p=     printf("Hexadecimal: %x %x %x %x\n",0, -1, 16, 2147483647);
	if(f == p)
	ft_printf("OK\n");
	else
	ft_printf("ft_printf: %i, printf: %i\n",f,p);

	f = ft_printf("Simbolo %%\n");
	p=     printf("Simbolo %%\n");
	if(f == p)
		ft_printf("OK\n");

	return (0);
}