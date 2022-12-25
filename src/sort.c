/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:36:39 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/26 00:01:53 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stacks *arr)
{
	if (2 != arr->a[2])
	{
		if (2 == arr->a[0])
			rotate(arr->a, arr->a_size, "up", "a");
		else
			rotate(arr->a, arr->a_size, "down", "a");
	}
	if (arr->a[0] > arr->a[1])
		swap("sa", arr->a, arr->a_size);
}

void	sort_4_5(t_stacks *arr)
{
	while (arr->b_size <= 1)
	{
		if (0 == arr->a[0] || 1 == arr->a[0])
			push("pb", arr);
		else
			rotate(arr->a, arr->a_size, "up", "a");
	}
	if (0 == arr->b[0])
		swap("sb", arr->b, arr->b_size);
	if (4 != arr->a[2])
	{
		if (4 == arr->a[0])
			rotate(arr->a, arr->a_size, "up", "a");
		else
			rotate(arr->a, arr->a_size, "down", "a");
	}
	if (arr->a[0] > arr->a[1])
		swap("sa", arr->a, arr->a_size);
	push("pa", arr);
	push("pa", arr);
}

void	sort_radix(t_stacks *arr)
{
	int	j;
	int	i;
	int	bit_size;
	int	size;

	i = 0;
	j = -1;
	bit_size = 8;
	if (arr->a_size == 100)
		bit_size = 6;
	while (++j <= bit_size)
	{
		i = -1;
		size = arr->a_size;
		while (++i < size)
		{
			if (((arr->a[0] >> j) & 1) == 0)
				push("pb", arr);
			else
				rotate(arr->a, arr->a_size, "up", "a");
		}
		while (arr->b_size != 0)
			push("pa", arr);
	}
}
