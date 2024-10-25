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

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char c = 'A';
	printf("%c\n", ft_tolower(c));
	return (0);
}*/
