#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char c = 'A';
	printf("%c\n", ft_tolower(c));
	return (0);
}*/
