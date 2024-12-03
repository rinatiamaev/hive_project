#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int a = 42;
	int *p = &a;
	char *str1 = NULL;

	/*printf("<-------Checking format------>\n");
	printf("<-------Standart------>\n");
	printf("");
	printf("%d, %s\n");
	printf("%d\n", 42, 0);
	printf("%z\n");
	printf("<--------My----------->\n");
	ft_printf("");
	ft_printf("%d, %s\n");
	ft_printf("%d\n", 42, 0);
	ft_printf("%z\n");*/
	printf("\n\n\n");

	printf("<-------Checking char------>\n");
	printf("<-------Standart------>\n");
	printf("%c, %c\n", 'a', 127);
	printf("%c, %c\n", '\0', '\n');
	printf("<--------My----------->\n");
	ft_printf("%c, %c\n", 'a', 127);
	ft_printf("%c, %c\n", '\0', '\n');
	printf("\n\n\n");
	printf("<-------Checking string------>\n");
	printf("<-------Standart------>\n");
	printf("%s\n", "H\\]*9213 ello, HIVE!!!");
	ft_printf("%s\n", "H\\]*9213 ello, HIVE!!!");
	printf("%s\n", "H\\ello, HIVE!!!\t\n\t\n");
	//printf("");
	int rval = printf("hello world\n");
	//printf("%s\n", str1);
	printf("<--------My----------->\n");
	ft_printf("%s\n", "Hello, HIVE!!!\t\n\t\n");
	int ft_rval = ft_printf("hello world\n");
	//ft_printf("");
	//ft_printf("%s\n", str1);
	printf("\n\n\n");
	printf("<-------Checking pointer------>\n");
	printf("<-------Standart------>\n");
	printf("%p\n", p);
	printf("%p\n", str1);
	printf("<--------My----------->\n");
	ft_printf("%p\n", p);
	ft_printf("%p\n", str1);
	printf("\n\n\n");
	printf("<-------Checking int------>\n");
	printf("<-------Standart------>\n");	
	printf("%d, %d, %i\n", -42, 1001, 2147483548);
	//printf("%d, %i\n", 214748364888);
	printf("<--------My----------->\n");
	ft_printf("%d, %d, %i\n", -42, 1001, 2147483548);
	//ft_printf("%d, %i\n", 214748364888);
	printf("\n\n\n");
	printf("<-------Checking unsigned int------>\n");
	printf("<-------Standart------>\n");
	printf("%u, %u\n", 1147483548, -100000);
	printf("<--------My----------->\n");
	ft_printf("%u, %u\n", 1147483548, -100000);
	printf("\n\n\n");
	printf("<-------Checking HEX------>\n");
	printf("<-------Standart------>\n");
	printf("%x, %X\n", 255, 255);
	printf("%x, %X\n", 0x0, 0xFFFFFFFF);
	printf("<--------My----------->\n");
	ft_printf("%x, %X\n", 255, 255);
	ft_printf("%x, %X\n", 0x0, 0xFFFFFFFF);
	printf("\n\n\n");
	printf("<-------Checking Percentage------>\n");
	printf("<-------Standart------>\n");
	printf("%%\n");
	//printf("%%%%%%\n");
	printf("<--------My----------->\n");
	ft_printf("%%\n");
	//ft_printf("%%%%%%\n");*/

	printf("<-------Checking return len------>\n");
	printf("%d %d\n", ft_printf("Hello\n"), printf("Hello\n"));
	printf("%d %d\n", rval, ft_rval);
	int n1 = printf("%d\n", 123123123);
	int n2 = ft_printf("%d\n", 123123123);
	printf("%d %d\n", n1, n2);
	return (0);
}
