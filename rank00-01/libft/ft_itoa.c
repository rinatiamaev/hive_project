/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:02:04 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 10:03:15 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_itoa(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		str_len;
	char	*res;
	long	temp;

	temp = n;
	str_len = ft_strlen_itoa(n);
	res = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!res)
		return (NULL);
	if (temp < 0)
	{
		res[0] = '-';
		temp = -temp;
	}
	res[str_len] = '\0';
	while (str_len-- > 0 && res[str_len] != '-')
	{
		res[str_len] = temp % 10 + '0';
		temp = temp / 10;
	}
	return (res);
}
