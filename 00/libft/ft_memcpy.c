void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char			*d;
	const unsigned char		*s;
	int						i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(void)
{
	char	src[] = "Hello, HIVE!";
	char	dest[20];

	ft_memcpy(dest, src, ft_strlen(src) + 1);
	printf("%s", dest);
	return (0);
}*/
