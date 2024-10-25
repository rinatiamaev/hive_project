/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:15:34 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/23 10:15:38 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		letter;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	letter = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == letter)
			return ((void *)(d + i + 1));
		i++;
	}
	return ((void *)0);
}
/*
#include <stdio.h>

int     ft_strlen(char *str)
{
        int     len;

        len = 0;
        while (str[len])
                len++;
        return (len);
}

int	main(void)
{
	char	src[] = "HELLO, HIVE!!!";
	char	dest[20];
	char	*res = ft_memccpy(dest, src, 'O', ft_strlen(src));
	if (res != (void *)0)
		printf("copying until 'O': %s:", dest);
	else
		printf(" 'O' not found");
	return (0);
}*/
