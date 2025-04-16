/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:18:15 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/09 20:01:50 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_three_a_and_b(t_stack *pile, int len)
{
	if (len == 3 && pile->size_a == 3)
		three_numbers_stack_a(pile);
	else if (len == 2)
	{
		if (pile->a[0] > pile->a[1])
			swap_a(pile, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(pile->a[0] < pile->a[1]
				&& pile->a[1] < pile->a[2]))
		{
			if (len == 3 && pile->a[0] > pile->a[1] && pile->a[0])
				swap_a(pile, 0);
			else if (len == 3 && !(pile->a[2] > pile->a[0]
					&& pile->a[2] > pile->a[1]))
				len = ft_push(pile, len, 0);
			else if (pile->a[0] > pile->a[1])
				swap_a(pile, 0);
			else if (len++)
				push_a(pile, 0);
		}
	}
}

int	median_of_numbers(int *pivot, int *pile, int size)
{
	int	*temp_stack;
	int	i;

	temp_stack = malloc(size * sizeof(int));
	if (!temp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		temp_stack[i] = pile[i];
		i++;
	}
	temporary_sort(temp_stack, size);
	*pivot = temp_stack[size / 2];
	free(temp_stack);
	return (1);
}

int	quicksort_stack_a(t_stack *pile, int len, int count_r)
{
	int	pivot;
	int	number;

	if (check_sorted(pile->a, len, 0) == 1)
		return (1);
	number = len;
	if (len <= 3)
	{
		quicksort_three_a_and_b(pile, len);
		return (1);
	}
	if (!median_of_numbers(&pivot, pile->a, len))
		return (0);
	while (len != number / 2 + number % 2)
	{
		if (pile->a[0] < pivot && (len--))
			push_b(pile, 0);
		else if (++count_r)
			rotate_a(pile, 0);
	}
	while (number / 2 + number % 2 != pile->size_a && count_r--)
		rev_rot_a(pile, 0);
	return (quicksort_stack_a(pile, number / 2 + number % 2, 0)
		&& quicksort_stack_b(pile, number / 2, 0));
	return (1);
}

int	three_numbers_stack_b(t_stack *pile, int len)
{
	if (len == 1)
		push_a(pile, 0);
	else if (len == 2)
	{
		if (pile->b[0] < pile->b[1])
			swap_b(pile, 0);
		while (len--)
			push_a(pile, 0);
	}
	else if (len == 3)
	{
		while (len || !(pile->a[0] < pile->a[1] && pile->a[1] < pile->a[2]))
		{
			if (len == 1 && pile->a[0] > pile->a[1])
				swap_a(pile, 0);
			else if (len == 1 || (len >= 2 && pile->b[0] > pile->b[1])
				|| (len == 3 && pile->b[0] > pile->b[2]))
				len = ft_push(pile, len, 1);
			else
				swap_b(pile, 0);
		}
	}
	return (0);
}

int	quicksort_stack_b(t_stack *pile, int len, int count_r)
{
	int	pivot;
	int	number;

	if (check_sorted(pile->b, len, 1) == 1)
		while (len--)
			push_a(pile, 0);
	if (len <= 3)
	{
		three_numbers_stack_b(pile, len);
		return (1);
	}
	number = len;
	if (!median_of_numbers(&pivot, pile->b, len))
		return (0);
	while (len != number / 2)
	{
		if (pile->b[0] >= pivot && len--)
			push_a(pile, 0);
		else if (++count_r)
			rotate_b(pile, 0);
	}
	while (pile->size_b != number / 2 && count_r--)
		rev_rot_b(pile, 0);
	return (quicksort_stack_a(pile, number / 2 + number % 2, 0)
		&& quicksort_stack_b(pile, number / 2, 0));
}
