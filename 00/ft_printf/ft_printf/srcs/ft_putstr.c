#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while(*str)
		len += write(1, str++, 1);
	return (len);
}
