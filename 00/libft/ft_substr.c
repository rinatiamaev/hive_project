#include "libft.h"

static int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_len;
	char		*substr;
	size_t		real_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	real_len = s_len - start;
	if (real_len > len)
		real_len = len;
	substr = (char *)malloc(real_len + 1);
	if (!substr)
		return (NULL);
	ft_strncpy(substr, s + start, real_len);
	substr[real_len] = '\0';
	return (substr);
}
/*
#include <stdio.h>

int	main(void)
{
	char *src = "Hello, HIVE!!!";
	char *substr = ft_substr(src, 7, 4);
	printf("%s", substr);
	return (0);
}*/
