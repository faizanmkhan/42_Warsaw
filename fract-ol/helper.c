/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:27:25 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/22 22:29:52 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

double	fo_atof(const char *s)
{
	double	result;
	double	exponent;
	int		sign;
	int		i;

	sign = 1;
	result = 0.0;
	exponent = 1.0;
	i = 0;
	if (s[i] == 45)
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
		result = result * 10 + (s[i++] - 48);
	if (s[i] == 46)
		i++;
	while (ft_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - 48);
		exponent = exponent * 10;
		i++;
	}
	return ((result * sign) / exponent);
}
