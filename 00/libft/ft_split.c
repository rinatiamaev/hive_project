/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:53:54 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/31 09:51:26 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char check, char c)
{
	return (check == c);
}

static int	count_words(char const *str, char c)
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

static char	*copy_word(char const *str, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		words;

	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_separator(s[i], c))
			i++;
		if (s[i])
		{
			res[j] = copy_word(&s[i], c);
			j++;
		}
		while (s[i] && !is_separator(s[i], c))
			i++;
	}
	res[j] = 0;
	return (res);
}
