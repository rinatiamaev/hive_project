/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:03:28 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 10:12:59 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	new_s = (char *)malloc(ft_strlen(s) + 1);
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
/*
#include <stdio.h>

char	ft_change_k(unsigned int i, char c)
{
	if (i < 100)
	{
		if (c == 'k')
			c = 'l';
	}
	return (c);
}

int	main(void)
{
	char *str = "Hekko, HIVE!!";
	char *new = ft_strmapi(str, ft_change_k);
	if (new)
	{
		printf("%s\n", new);
		free(new);
	}
	else
		printf("Memory allocated failed\n");
	return (0);
}*/
