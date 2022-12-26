/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:36:39 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/26 22:47:50 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stacks *stack)
{
	if (2 != stack->a[2])
	{
		if (2 == stack->a[0])
			rotate(stack->a, stack->a_size, "up", "a");
		else
			rotate(stack->a, stack->a_size, "down", "a");
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack->a, stack->a_size);
}

void	sort_four_to_five(t_stacks *stack)
{
	while (stack->b_size <= 1)
	{
		if (0 == stack->a[0] || 1 == stack->a[0])
			push("pb", stack);
		else
			rotate(stack->a, stack->a_size, "up", "a");
	}
	if (0 == stack->b[0])
		swap("sb", stack->b, stack->b_size);
	if (4 != stack->a[2])
	{
		if (4 == stack->a[0])
			rotate(stack->a, stack->a_size, "up", "a");
		else
			rotate(stack->a, stack->a_size, "down", "a");
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack->a, stack->a_size);
	push("pa", stack);
	push("pa", stack);
}

void	sort_using_radix_sort(t_stacks *stack)
{
	int	j;
	int	i;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	i = 0;
	j = -1;
	while (++j <= bit_size)
	{
		i = -1;
		size = stack->a_size;
		while (++i < size)
		{
			if (((stack->a[0] >> j) & 1) == 0)
				push("pb", stack);
			else
				rotate(stack->a, stack->a_size, "up", "a");
		}
		while (stack->b_size != 0)
			push("pa", stack);
	}
}
