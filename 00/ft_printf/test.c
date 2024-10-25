#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int a = 42;
	int *p = &a;
	printf("Here is standart printf\n");
	printf("%c, %c\n", 'a', 100);
	printf("%s\n", "Hello, HIVE!!!");
	printf("%p\n", p);
	printf("%d, %i\n", -42, 1001);
	printf("%u\n", 1);
	printf("%x, %X\n", 255, 255);
	printf("%%\n");
	ft_printf("Here is my implementing of printf\n");
	ft_printf("%c, %c\n", 'a', 100);
	ft_printf("%s\n", "Hello, HIVE!!!");
	ft_printf("%p\n", p);
	ft_printf("%d, %i\n", -42, 1001);
	ft_printf("%u\n", 1);
	ft_printf("%x, %X\n", 255, 255);
	ft_printf("%%\n");
	return (0);
}
