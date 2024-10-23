#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	buffer[15];
	int		i = 0;
	ft_bzero(buffer, sizeof(buffer));
	while (i < (int)sizeof(buffer))
	{
		printf("%d ", buffer[i]);
		i++;
	}
	return (0);
}*/