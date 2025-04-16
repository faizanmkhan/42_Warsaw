/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:58:23 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/04 19:27:37 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	temporary_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	three_numbers_stack_a(t_stack *three)
{
	if (three->a[0] > three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] < three->a[2])
		swap_a(three, 0);
	if (three->a[0] > three->a[1] && three->a[1] > three->a[2]
		&& three->a[0] > three->b[2])
	{
		swap_a(three, 0);
		rev_rot_a(three, 0);
	}
	if (three->a[0] < three->a[1] && three->a[1] > three->a[2]
		&& three->a[2] > three->a[0])
	{
		swap_a(three, 0);
		rotate_a(three, 0);
	}
	if (three->a[0] < three->a[1] && three->a[1] > three->a[2]
		&& three->a[2] < three->a[0])
		rev_rot_a(three, 0);
	if (three->a[0] > three->a[1] && three->a[1] < three->a[2]
		&& three->a[2] < three->a[0])
		rotate_a(three, 0);
}

int	sort(t_stack *pile, int size)
{
	if (check_sorted(pile->a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile, 0);
		else if (size == 3)
			three_numbers_stack_a(pile);
		else
			quicksort_stack_a(pile, size, 0);
	}
	return (0);
}

int	ft_push(t_stack *pile, int len, int push)
{
	if (push == 0)
		push_b(pile, 0);
	else
		push_a(pile, 0);
	len--;
	return (len);
}

void	free_pile(int *pile_a, int *pile_b)
{
	free(pile_a);
	free(pile_b);
}
