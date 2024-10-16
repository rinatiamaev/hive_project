void	ft_bzero(void *s, int n)
{
	int				i;
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
