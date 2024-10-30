/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:20:54 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/28 15:42:30 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = (void *)0;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)(last));
}
/*
#include <stdio.h>

int	main(void)
{
	const char *str = "Hello, HIVE!!!";
	char c = 'H';
	char *res = ft_strrchr(str, c);
	if (res != (void *)0)
		printf("Last character '%c' 
		found in position: %ld, 
		in string 'Hello, HIVE!!!'", c, res - str);
	else
		printf("Character %c not found in string", c);
	return (0);
}*/
