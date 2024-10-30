/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:12:23 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/28 15:13:42 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char c = 'a';
	char d = '8';
	printf("%c\n", ft_toupper(c));
	printf("%c\n", ft_toupper(d));
	return (0);
}*/
