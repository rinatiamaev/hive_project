#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, int destsize)
{
	int	i;
	int	srclen;

	i = 0;
	while (src[srclen])
		srclen++;
	if (destsize > 0)
	{
		while (i < destsize - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclen);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "Hello, HIVE!";
	char dest[6];
	int len = ft_strlcpy(dest, src, sizeof(dest));
	printf("copied string: %s\n", dest);
	printf("length of src string: %d\n", len);
	return (0);
}*/
