void	*ft_memset(void *s, int c, int n)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	buffer[15];
	int		i = 0;
	ft_memset(buffer, 'X', sizeof(buffer));
	while (i < (int)sizeof(buffer))
	{
		printf("%c ", buffer[i]);
		i++;
	}
	return (0);
}*/
