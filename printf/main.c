#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
	int f,p;
	ft_printf("\n---- FT_PRINTF ----\n");
	f = ft_printf("Characters: %c %c %c %c %c\n",'a',99, 125+1, -1, 200);
	p=     printf("Characters: %c %c %c %c %c\n",'a',99, 125+1, -1, 200);
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	f = ft_printf("String: %s\n","Hola Mundo");
	p=     printf("String: %s\n","Hola Mundo");
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	f = ft_printf("Integer: %i %i %i %i\n",9, 100+20+3, -5, 0);
	p=     printf("Integer: %i %i %i %i\n",9, 100+20+3, -5, 0);
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	f = ft_printf("Decimal: %d %d %d %d\n",9, 100+20+3, -5, 0);
	p=     printf("Decimal: %d %d %d %d\n",9, 100+20+3, -5, 0);
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	f = ft_printf("Unsigned int: %u %u %u %u %u\n",9, 100+20+3, -5, 0, 1000000000);
	p=     printf("Unsigned int: %u %u %u %u %u\n",9, 100+20+3, -5, 0, 1000000000);
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	f = ft_printf("Hexadecimal: %x %x %x %x %x\n",9, 100+20+3, -5, 0, 1000000000);
	p=     printf("Hexadecimal: %x %x %x %x %x\n",9, 100+20+3, -5, 0, 1000000000);
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	f = ft_printf("Hexadecimal: %X %X %X %X %X\n",9, 100+20+3, -5, 0, 1000000000);
	p=     printf("Hexadecimal: %X %X %X %X %X\n",9, 100+20+3, -5, 0, 1000000000);
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	f = ft_printf("Simbolo %%\n");
	p=     printf("Simbolo %%\n");
	ft_printf("Bytes usados: ft_printf: %i \\ printf: %i\n\n",f,p);

	return (0);
}