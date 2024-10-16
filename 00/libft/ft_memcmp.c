int	ft_memcmp(const void *s1, const void *s2, int n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	int					i;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "abc";
	char s2[] = "abb";
	printf("%d", ft_memcmp(s1, s2, 3));
	return (0);
}*/
