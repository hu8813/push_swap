/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:30 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/26 23:44:16 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_if_sorted_or_has_duplicate(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_size)
	{
		j = i + 1;
		while (j < stack->a_size)
		{
			if (stack->a[i] == stack->a[j])
				free_and_exit_with_message(stack, "Error\n");
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			return ;
		}
		i++;
	}
	free_and_exit_with_message(stack, NULL);
}

void	parse_numbers(int argc, char **argv, t_stacks *stack)
{
	int	i;
	int	k;
	int	j;
	int	z;

	k = 0;
	j = 0;
	z = 0;
	while (argc-- > 1)
	{
		j = ft_count_words(argv[z + 1], ' ');
		if (j == 1)
			stack->a[k] = ft_atoi(argv[z + 1]);
		else if (j > 1)
		{
			stack->tmparr = ft_split(argv[z + 1], ' ');
			while (j--)
				stack->a[k++] = ft_atoi(stack->tmparr[i++]);
			i = 0;
			while (stack->tmparr[i])
				free(stack->tmparr[i++]);
			free(stack->tmparr);
			k--;
		}
		z++;
		k++;
	}
}

void	initialize_stacks(int argc, char **argv, t_stacks *stack)
{
	int	i;

	i = 0;
	stack->tmparr = 0;
	stack->a_size = 0;
	stack->b_size = 0;
	while (--argc)
		stack->a_size += ft_count_words(argv[i++], ' ');
	stack->a = malloc(stack->a_size * sizeof * stack->a);
	stack->b = malloc(stack->a_size * sizeof * stack->b);
}

void	create_index(t_stacks *stack)
{
	int	*new_a;
	int	i;
	int	j;
	int	k;
	int	min;

	new_a = malloc(sizeof * new_a * stack->a_size);
	i = 0;
	while (i < stack->a_size)
	{
		j = 0;
		min = 2147483647;
		while (j < stack->a_size)
		{
			if (min > stack->a[j++])
			{
				min = stack->a[j - 1];
				k = j - 1;
			}
		}
		stack->a[k] = 2147483647;
		new_a[k] = i++;
	}
	free(stack->a);
	stack->a = new_a;
}

void	free_and_exit_with_message(t_stacks *ptr, char *err)
{
	if (err)
		write(2, err, ft_strlen(err));
	if (ptr != NULL)
	{
		if (ptr->a != NULL)
			free(ptr->a);
		if (ptr->b != NULL)
			free(ptr->b);
		if (ptr != NULL)
			free(ptr);
	}
	exit(1);
}
