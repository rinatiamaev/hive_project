int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
#include <stdio.h>

int	main(void)
{
	char c1 = 'a';
	char c2 = 'Z';
	char c3 = '3';
	printf("%d\n", ft_isalpha(c1));
	printf("%d\n", ft_isalpha(c2));
	printf("%d\n", ft_isalpha(c3));
	return (0);
}*/
