/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:12 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/29 23:31:22 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_and_exit_with_message(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	if (argc < 2)
		exit(0);
	s = malloc(sizeof * s);
	initialize_stacks(argc, argv, s);
	parse_numbers(argc, argv, s);
	exit_if_sorted_or_has_duplicate(s);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_to_five(s);
	else
		sort_using_radix_sort(s);
	exit_if_sorted_or_has_duplicate(s);
	free_and_exit_with_message(s, "Error\n");
	return (0);
}
