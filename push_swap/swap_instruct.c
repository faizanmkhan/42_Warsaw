/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:36:57 by faikhan           #+#    #+#             */
/*   Updated: 2024/12/29 17:42:47 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *ptr, int print)
{
	int	temp;

	if (ptr->size_a == 0 || ptr->size_a == 1)
		return ;
	temp = 0;
	temp = ptr->a[0];
	ptr->a[0] = ptr->a[1];
	ptr->a[1] = temp;
	if (!print)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *ptr, int print)
{
	int	temp;

	if (ptr->size_b == 0 || ptr->size_b == 1)
		return ;
	temp = 0;
	temp = ptr->b[0];
	ptr->b[0] = ptr->b[1];
	ptr->b[1] = temp;
	if (!print)
		write(1, "sb\n", 3);
}

void	swap_s(t_stack *ptr, int print)
{
	int	temp;

	if ((ptr->size_a == 0 || ptr->size_a == 1)
		|| (ptr->size_b == 0 || ptr->size_b == 1))
		return ;
	temp = 0;
	temp = ptr->a[0];
	ptr->a[0] = ptr->a[1];
	ptr->a[1] = temp;
	temp = ptr->b[0];
	ptr->b[0] = ptr->b[1];
	ptr->b[1] = temp;
	if (!print)
		write(1, "ss\n", 3);
}
