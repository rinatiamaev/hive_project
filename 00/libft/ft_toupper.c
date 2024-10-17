#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char c = 'a';
	printf("%c\n", ft_toupper(c));
	return (0);
}*/
