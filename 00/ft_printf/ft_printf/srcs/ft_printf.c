#include "../ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				len += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (*format == 'p')
				len += ft_putpointer((unsigned long long)va_arg(args, void *));
			else if (*format == 'd' || *format == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				len += ft_putui(va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X')
				len += ft_puthex(va_arg(args, unsigned int), *format);
			else if (*format == '%')
				len += ft_putchar('%');
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
/*
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
}*/
