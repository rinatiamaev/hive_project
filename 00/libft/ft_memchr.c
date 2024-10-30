/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:53 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 12:30:35 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		letter;
	size_t				i;

	ptr = (const unsigned char *)s;
	letter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == letter)
			return ((void *)(ptr + i));
		i++;
	}
	return ((void *)0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c = 'F';
	char	str[] = "Hello, Friends!";
	char	*res = ft_memchr(str, c, ft_strlen(str));
	if (res != (void *)0)
		printf("Character '%c' found in position:
	       	%ld, in string 'Hello, Friends'", c, res - str);
	else
		printf("Character not found\n");
	return (0);
}*/
