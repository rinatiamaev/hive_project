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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
/*
int	main(void)
{
	int n = 0;
	int n1 = 100;
	int n2 = -9100076;
	int n3 = -2147483648;
	int fd = 1;
	ft_putnbr_fd(n, fd);
	write(1, "\n", 1);
        ft_putnbr_fd(n1, fd);
        write(1, "\n", 1);
        ft_putnbr_fd(n2, fd);
        write(1, "\n", 1);
        ft_putnbr_fd(n3, fd);
        write(1, "\n", 1);
	return (0);
}*/
