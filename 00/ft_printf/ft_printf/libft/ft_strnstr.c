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

char	*ft_strnstr(const char *str, const char *to_find, int len)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] && str[i + j] == to_find[j] && (i + j) < len)
				j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return ((void *)0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char *str = "Hello, HIVE!!!";
	const char *to_find = "HIVE";
	int len = 12;
	char *res = ft_strnstr(str, to_find, len);
	if (res != (void *)0)
		printf("String %s found in string %s: \n", to_find, res);
	else
		printf("Not found");
	return (0);

}*/
