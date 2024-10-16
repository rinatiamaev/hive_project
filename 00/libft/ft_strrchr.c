char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = (void *)0;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)(last));
}
/*
#include <stdio.h>

int	main(void)
{
	const char *str = "Hello, HIVE!!!";
	char c = 'H';
	char *res = ft_strrchr(str, c);
	if (res != (void *)0)
		printf("Character %c found in position: %ld", c, res - str);
	else
		printf("Character %c not found in string", c);
	return (0);
}*/
