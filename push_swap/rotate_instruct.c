/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:43:58 by faikhan           #+#    #+#             */
/*   Updated: 2024/12/29 17:36:29 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *ptr, int print)
{
	int	temp;
	int	i;

	if (ptr->size_a == 0 || ptr->size_a == 1)
		return ;
	i = 0;
	temp = ptr->a[i];
	i++;
	while (i < ptr->size_a)
	{
		ptr->a[i - 1] = ptr->a[i];
		i++;
	}
	ptr->a[i - 1] = temp;
	if (!print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *ptr, int print)
{
	int	temp;
	int	i;

	if (ptr->size_b == 0 || ptr->size_b == 1)
		return ;
	i = 0;
	temp = ptr->b[i];
	i++;
	while (i < ptr->size_b)
	{
		ptr->b[i - 1] = ptr->b[i];
		i++;
	}
	ptr->b[i - 1] = temp;
	if (!print)
		write(1, "rb\n", 3);
}

void	rotate_r(t_stack *ptr, int print)
{
	int	temp;
	int	i;

	if ((ptr->size_a == 0 || ptr->size_a == 1)
		|| (ptr->size_b == 0 || ptr->size_b == 1))
		return ;
	i = 0;
	temp = ptr->a[i];
	while (++i < ptr->size_a)
		ptr->a[i - 1] = ptr->a[i];
	ptr->a[i - 1] = temp;
	i = 0;
	temp = ptr->b[i];
	while (++i < ptr->size_b)
		ptr->b[i - 1] = ptr->b[i];
	ptr->b[i - 1] = temp;
	if (!print)
		write(1, "rr\n", 3);
}
