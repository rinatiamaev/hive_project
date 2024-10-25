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

int	ft_strlcat(char *dest, char *src, int destsize)
{
	int	destlen;
	int	srclen;
	int	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	if (destsize <= destlen)
		return (destsize + srclen);
	while (src[i] && ((destlen + i) < (destsize - 1)))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[15] = "Hello";
	char	src[] = " HIVE!!!";
	int	len = ft_strlcat(dest, src, sizeof(dest));
	printf("length that try to created: %d\n", len);
	printf("result string: %s\n", dest);
	return (0);
}*/
