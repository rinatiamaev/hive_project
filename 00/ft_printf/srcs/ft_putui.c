#include "../ft_printf.h"

int	ft_putui(unsigned int n)
{
	if (n >= 10)
		return (ft_putui(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}
