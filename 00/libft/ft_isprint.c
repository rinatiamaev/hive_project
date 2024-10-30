/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:16:27 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/28 14:18:29 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
/*
#include <stdio.h>

int	main(void)
{
	char c = 'a';
	char d = '\n';
	printf("%d\n", ft_isprint(c));
	printf("%d\n", ft_isprint(d));
	return (0);
}*/
