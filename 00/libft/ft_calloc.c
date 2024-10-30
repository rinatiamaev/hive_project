/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:29:08 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 12:36:28 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmem, size_t size)
{
	size_t		total;
	void		*ptr;

	total = nmem * size;
	if (nmem != 0 && total / nmem != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	size_t *arr;
	size_t n = 10;
	size_t i = 0;
	arr = (size_t *)ft_calloc(n, sizeof(size_t));
	if (arr == NULL)
	{
		printf("memory allocation failed\n");
		return (1);
	}
	while (i < n)
	{
		printf("%ld\n", arr[i++]);
	}
	free (arr);
	return (0);
	
}*/
