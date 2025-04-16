/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:53:00 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/04 18:51:07 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *ptr, int print)
{
	int	i;

	if (ptr->size_a)
	{
		ptr->size_b++;
		i = ptr->size_b;
		while (--i > 0)
			ptr->b[i] = ptr->b[i - 1];
		ptr->b[0] = ptr->a[0];
		i = 0;
		ptr->size_a--;
		while (i < ptr->size_a)
		{
			ptr->a[i] = ptr->a[i + 1];
			i++;
		}
		if (!print)
			write(1, "pb\n", 3);
	}
	else
		return ;
}

void	push_a(t_stack *ptr, int print)
{
	int	i;

	if (ptr->size_b)
	{
		ptr->size_a++;
		i = ptr->size_a;
		while (--i > 0)
			ptr->a[i] = ptr->a[i - 1];
		ptr->a[0] = ptr->b[0];
		i = 0;
		ptr->size_b--;
		while (i < ptr->size_b)
		{
			ptr->b[i] = ptr->b[i + 1];
			i++;
		}
		if (!print)
			write(1, "pa\n", 3);
	}
	else
		return ;
}
