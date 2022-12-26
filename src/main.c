/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:12 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/26 23:42:45 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	validate_arguments(int argc, char **argv)
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
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && (argv[i][j] != '-'
					&& argv[i][j] != '+') && argv[i][j] != ' ')
				free_and_exit_with_message(NULL, "Error\n");
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	validate_arguments(argc, argv);
	s = malloc(sizeof * s);
	initialize_stacks(argc, argv, s);
	parse_numbers(argc, argv, s);
	check_if_sorted_or_has_duplicate(s);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_to_five(s);
	else
		sort_using_radix_sort(s);
	free_and_exit_with_message(s, NULL);
	return (0);
}
