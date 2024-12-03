/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:10:18 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/06 10:10:20 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned long long n, const char type)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16, type);
		len += ft_puthex(n % 16, type);
	}
	else
	{
		if (n < 10)
			len += ft_putchar(n + '0');
		else
		{
			if (type == 'x')
				len += ft_putchar(n - 10 + 'a');
			else if (type == 'X')
				len += ft_putchar(n - 10 + 'A');
		}
	}
	return (len);
}
