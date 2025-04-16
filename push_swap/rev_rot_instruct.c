/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:45:58 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/02 19:06:28 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_a(t_stack *ptr, int print)
{
	int	temp;
	int	i;

	if (ptr->size_a == 0 || ptr->size_a == 1)
		return ;
	i = ptr->size_a - 1;
	temp = ptr->a[i];
	while (i)
	{
		ptr->a[i] = ptr->a[i - 1];
		i--;
	}
	ptr->a[i] = temp;
	if (!print)
		write(1, "rra\n", 4);
}

void	rev_rot_b(t_stack *ptr, int print)
{
	int	temp;
	int	i;

	if (ptr->size_b == 0 || ptr->size_b == 1)
		return ;
	i = ptr->size_b - 1;
	temp = ptr->b[i];
	while (i)
	{
		ptr->b[i] = ptr->b[i - 1];
		i--;
	}
	ptr->b[i] = temp;
	if (!print)
		write(1, "rrb\n", 4);
}

void	rev_rot_r(t_stack *ptr, int print)
{
	int	temp;
	int	i;

	if ((ptr->size_b == 0 || ptr->size_b == 1)
		|| (ptr->size_a == 0 || ptr->size_a == 1))
		return ;
	i = ptr->size_a - 1;
	temp = ptr->a[i];
	while (i)
	{
		ptr->a[i] = ptr->a[i - 1];
		i--;
	}
	ptr->a[i] = temp;
	i = ptr->size_b - 1;
	temp = ptr->b[i];
	while (i)
	{
		ptr->b[i] = ptr->b[i - 1];
		i--;
	}
	ptr->b[i] = temp;
	if (!print)
		write(1, "rrr\n", 4);
}
