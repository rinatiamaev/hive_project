#include "../ft_printf.h"

int	ft_putpointer(unsigned long long p)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_puthex(p, 'x') + 2);
}
