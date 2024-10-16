#include <stdlib.h>

static int	ft_strlen_itoa(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		str_len;
	char	*res;
	long	temp;

	temp = n;
	str_len = ft_strlen_itoa(n);
	res = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!res)
		return (NULL);
	if (temp < 0)
	{
		res[0] = '-';
		temp = -temp;
	}
	res[str_len] = '\0';
	while (str_len-- > 0 && res[str_len] != '-')
	{
		res[str_len] = temp % 10 + '0';
		temp = temp / 10;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int n = 97519890;
	int m = -2098309;
	int k = 0;
	int s = -2147483648;
	printf("%s\n", ft_itoa(n));
	printf("%s\n", ft_itoa(m));
	printf("%s\n", ft_itoa(k));
	printf("%s\n", ft_itoa(s));
	return (0);
}*/
