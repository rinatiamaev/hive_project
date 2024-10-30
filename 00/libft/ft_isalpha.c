/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:47:37 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/28 14:15:43 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
#include <stdio.h>

int	main(void)
{
	char c1 = 'a';
	char c2 = 'Z';
	char c3 = '3';
	printf("%d\n", ft_isalpha(c1));
	printf("%d\n", ft_isalpha(c2));
	printf("%d\n", ft_isalpha(c3));
	return (0);
}*/
