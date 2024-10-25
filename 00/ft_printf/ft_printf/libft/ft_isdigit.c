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

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>

int	main(void)
{
	char c1 = '7';
	char c2 = 'a';
	printf("%d\n", ft_isdigit(c1));
	printf("%d\n", ft_isdigit(c2));
	return (0);
}*/
