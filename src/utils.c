/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:30 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/27 15:50:59 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_if_sorted_or_has_duplicate(t_stacks *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->a_size)
	{
		j = i + 1;
		while (j < s->a_size)
		{
			if (s->a[i] == s->a[j])
				free_and_exit_with_message(s, "Error\n");
			j++;
		}
		i++;
	}
	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return ;
		i++;
	}
	free_and_exit_with_message(s, NULL);
}

void	parse_numbers(int argc, char **argv, t_stacks *s)
{
	char	**tmp;
	int		i;
	int		j;
	int		z;

	z = 0;
	while (argc-- > 1)
	{
		j = ft_count_words(argv[z + 1], ' ');
		if (j == 1)
			s->a[z] = ft_atoi(argv[z + 1]);
		else if (j > 1)
		{
			tmp = ft_split(argv[z + 1], ' ');
			i = 0;
			while (j--)
				s->a[z++] = ft_atoi(tmp[i++]);
			while (tmp[i])
				free(tmp[i++]);
			z--;
		}
		z++;
	}
}

void	initialize_stacks(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
		s->a_size += ft_count_words(argv[i++], ' ');
	s->a = malloc(s->a_size * sizeof * s->a);
	s->b = malloc(s->a_size * sizeof * s->b);
}

void	create_index(t_stacks *s)
{
	int	*new_a;
	int	i;
	int	j;
	int	k;
	int	min;

	new_a = malloc(s->a_size * sizeof * new_a);
	i = 0;
	while (i < s->a_size)
	{
		j = 0;
		min = 2147483647;
		while (j < s->a_size)
		{
			if (min > s->a[j++])
			{
				min = s->a[j - 1];
				k = j - 1;
			}
		}
		s->a[k] = 2147483647;
		new_a[k] = i++;
	}
	free(s->a);
	s->a = new_a;
}

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
