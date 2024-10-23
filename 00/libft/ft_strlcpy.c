#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
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
