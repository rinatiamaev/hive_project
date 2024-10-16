#include <stdlib.h>

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

void	*ft_calloc(int nmem, int size)
{
	int		total;
	void	*ptr;

	total = nmem * size;
	if (nmem != 0 && total / nmem != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int *arr;
	int n = 10;
	int i = 0;
	arr = (int *)ft_calloc(n, sizeof(int));
	if (arr == NULL)
	{
		printf("memory allocation failed\n");
		return (1);
	}
	while (i < n)
	{
		printf("%d\n", arr[i++]);
	}
	free (arr);
	return (0);
	
}*/
