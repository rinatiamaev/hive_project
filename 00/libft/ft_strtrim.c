#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*trim_str;

	if (!s1 || !set)
		return (NULL);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trim_str = (char *)malloc(len + 1);
	if (!trim_str)
		return (NULL);
	ft_strncpy(trim_str, &s1[start], len);
	trim_str[len] = '\0';
	return (trim_str);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = " ,2Hello, HIVE!, 2";
	char *set = ", 2";
	char *trim_str = ft_strtrim(str, set);
	if (trim_str)
	{
		printf("%s", trim_str);
		free(trim_str);
	}
	else
		printf("Memory allocated failed");
	return (0);
}*/
