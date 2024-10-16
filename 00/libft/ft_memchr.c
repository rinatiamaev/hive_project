void	*ft_memchr(const void *s, int c, int n)
{
	const unsigned char	*ptr;
	unsigned char		letter;
	int					i;

	ptr = (const unsigned char *)s;
	letter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == letter)
			return ((void *)(ptr + i));
		i++;
	}
	return ((void *)0);
}
/*
#include <stdio.h>

int     ft_strlen(char *str)
{
        int     len;

        len = 0;
        while (str[len])
                len++;
        return (len);
}

int	main(void)
{
	char	str[] = "Hello, Friends!";
	char	*res = ft_memchr(str, 'F', ft_strlen(str));
	if (res != (void *)0)
		printf("Character found in position %ld", res - str);
	else
		printf("Character not found\n");
	return (0);
}*/
