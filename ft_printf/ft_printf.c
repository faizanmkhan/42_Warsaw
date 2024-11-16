/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:38:36 by faikhan           #+#    #+#             */
/*   Updated: 2024/11/07 14:41:57 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_specifiers(va_list ap, char c)
{
	int	i;

	i = 0;
	if (c == 99)
		i += ft_putchar(va_arg(ap, int));
	else if (c == 115)
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 100 || c == 105)
		i += ft_putnbr(va_arg(ap, int));
	else if (c == 117)
		i += ft_putnbr(va_arg(ap, unsigned int));
	else if (c == 88)
		i += ft_puthex_up(va_arg(ap, unsigned int));
	else if (c == 120)
		i += ft_puthex_low(va_arg(ap, unsigned int));
	else if (c == 112)
		i += ft_putptr(va_arg(ap, void *));
	else if (c == 37)
		i += ft_putchar(37);
	else
		i += write(1, "Unsupported format specifier \n", 30);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		byte_printed;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	byte_printed = 0;
	while (format[i])
	{
		if (format[i] == 37)
			byte_printed += ft_specifiers(ap, format[++i]);
		else
			byte_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (byte_printed);
}
