/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:20 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/25 23:54:48 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_ab(char *s, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(s, 1);
}

void	push_ab(char *s, t_stacks *arr)
{
	int	tmp;

	if (ft_strncmp(s, "pa", 3) == 0)
	{
		if (arr->b_size <= 0)
			return ;
		tmp = arr->b[0];
		ft_memmove(arr->a + 1, arr->a, sizeof(int) * arr->a_size);
		arr->a[0] = tmp;
		arr->b_size--;
		ft_memmove(arr->b, arr->b + 1, sizeof(int) * arr->b_size);
		arr->a_size++;
	}
	else if (ft_strncmp(s, "pb", 3) == 0)
	{
		if (arr->a_size <= 0)
			return ;
		tmp = arr->a[0];
		ft_memmove(arr->b + 1, arr->b, sizeof(int) * arr->b_size);
		arr->b[0] = tmp;
		arr->a_size--;
		ft_memmove(arr->a, arr->a + 1, sizeof(int) * arr->a_size);
		arr->b_size++;
	}
	ft_putendl_fd(s, 1);
}

void	rotate_ab(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
