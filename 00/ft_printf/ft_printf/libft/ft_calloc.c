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

void	*ft_calloc(int nmem, int size)
{
	int		total;
	void	*ptr;

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
	int *arr;
	int n = 10;
	int i = 0;
	arr = (int *)ft_calloc(n, sizeof(int));
	if (arr == NULL)
	{
		printf("memory allocation failed\n");
		return (1);
	}
	while (i < n)
	{
		printf("%d\n", arr[i++]);
	}
	free (arr);
	return (0);
	
}*/
