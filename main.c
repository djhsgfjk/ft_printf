#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int n;
	unsigned char a=0x64;
	int b=0x00DEF923;
	
	int i = 10;
	int d = -10;


	n = printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%", 35, "Hello, World!", &i, d, i, i, a, b);
	//n = printf("%x\n%X\n%p\n%p\n", a, b, &a, &b);
	printf("%d\n\n", n);

	n = ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%", 35, "Hello, World!", &i, d, i, i, a, b);
	//n = ft_printf("%x\n%X\nf%p\n%p\n", a, b, &a, &b);
	ft_printf("%d\n", n);
	return 0;
}
