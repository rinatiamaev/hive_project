/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:11:10 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/06 10:11:11 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putui(unsigned int n)
{
	if (n >= 10)
		return (ft_putui(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}
