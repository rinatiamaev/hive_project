/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:09:22 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/12 09:30:35 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_format(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putpointer((unsigned long long)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putui(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	else
	{
		ft_putstr("Not supported format\n");
		return (-1);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		errorcheck;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			errorcheck = check_format(*format, args);
			if (errorcheck == -1)
			{
				va_end(args);
				return (-1);
			}
			len += errorcheck;
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
