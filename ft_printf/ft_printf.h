/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:33:56 by faikhan           #+#    #+#             */
/*   Updated: 2024/11/06 17:33:10 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_specifiers(va_list ap, char c);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long int n);
int	ft_puthex_low(unsigned long int n);
int	ft_puthex_up(unsigned int n);
int	ft_putptr(void *ptr);

#endif
