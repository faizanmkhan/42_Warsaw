/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:10:58 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/04 13:31:06 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	p_s_atoi(char *str, t_stack *ptr, char **argv)
{
	unsigned int		i;
	unsigned long int	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == 43 || str[i] == 45)
	{
		if (!ft_isdigit(str[i + 1]))
			error_atoi(ptr, argv);
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			error_atoi(ptr, argv);
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if ((res > 2147483648 && sign == -1) || (res > 2147483647 && sign == 1))
		error_atoi(ptr, argv);
	return (res * sign);
}
