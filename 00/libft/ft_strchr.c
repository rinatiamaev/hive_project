/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:15:35 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/28 15:18:48 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((void *)0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char *str = "Hello, HIVE!";
	char c = '!';
	char *res = ft_strchr(str, c);
	if (res != (void *)0)
		printf("Letter '%c' found in position:
		%ld, in string 'Hello, HIVE!'\n", c, res - str);
	else
		printf("Letter %c not found in string", c);
	return (0);
}*/
