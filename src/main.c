/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:12 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/25 16:06:40 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(0);
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j] != '-')
				ft_exit(NULL, "Error\n");
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_array_value	*arr;

	check_args(argc, argv);
	arr = malloc(sizeof * arr);
	arg_count(argc, argv, arr);
	arr->a = malloc(arr->k * sizeof * arr->a);
	arr->b = malloc(arr->k * sizeof * arr->b);
	arg_count2(argc, argv, arr);
	if (arr->a_size > 1)
	{
		make_index(arr);
		if (arr->a_size == 2 && arr->a[0] > arr->a[1])
			swap_ab("sa", arr->a, arr->a_size);
		else if (arr->a_size == 3)
			sort_3(arr);
		else if (arr->a_size >= 4 && arr->a_size <= 5)
			sort_4_5(arr);
		else
			sort_radix(arr);
	}
	ft_exit(arr, NULL);
	return (0);
}
