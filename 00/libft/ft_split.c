#include "libft.h"

static int	is_separator(char check, char c)
{
	if (check == c)
		return (1);
	return (0);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], c))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_separator(str[i], c))
			i++;
	}
	return (count);
}

static char	*copy_word(char *str, char c)
{
	int		i;
	char	*word;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && !is_separator(str[len], c))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**result;
	int		i;
	int		j;
	int		words;

	words = count_words(str, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], c))
			i++;
		if (str[i])
		{
			result[j] = copy_word(&str[i], c);
			j++;
		}
		while (str[i] && !is_separator(str[i], c))
			i++;
	}
	result[j] = 0;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**result = ft_split("FORD KIA MERS BMW TESLA", ' ');
	int i = 0;
	
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0); 
}*/
