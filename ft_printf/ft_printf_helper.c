/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:33:52 by faikhan           #+#    #+#             */
/*   Updated: 2024/11/06 17:33:58 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += write (1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		write (1, str + i, 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar(45);
		i += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

int	ft_puthex_low(unsigned long int n)
{
	int		i;
	char	*digit;

	digit = "0123456789abcdef";
	i = 0;
	if (n >= 16)
	{
		i += ft_puthex_low(n / 16);
		i += ft_puthex_low(n % 16);
	}
	else
		i += write(1, &digit[n], 1);
	return (i);
}

int	ft_puthex_up(unsigned int n)
{
	int		i;
	char	*digit;

	digit = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
	{
		i += ft_puthex_up(n / 16);
		i += ft_puthex_up(n % 16);
	}
	else
		i += write(1, &digit[n], 1);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int			i;
	uintptr_t	address;

	address = (uintptr_t) ptr;
	i = 0;
	if (!address)
		i += write(1, "(nil)", 5);
	else
	{
		i += ft_putstr("0x");
		i += ft_puthex_low(address);
	}
	return (i);
}
