#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	char *res;
	int		len;

	res = ft_itoa(n);
	if (!res)
		return (0);
	len = ft_putstr(res);
	free(res);
	return (len);
}
