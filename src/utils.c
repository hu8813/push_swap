/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:30 by huaydin           #+#    #+#             */
/*   Updated: 2023/04/09 16:26:17 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
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
	}
	if (is_array_sorted(s))
		free_and_exit_with_message(s, NULL);
}

void	parse_numbers(t_stacks *s)
{
	int		i;
	int		z;

	z = 0;
	s->tmp = ft_split(s->join_args, ' ');
	i = 0;
	while (s->tmp[i] != NULL && s->tmp[i][0] != '\0')
	{
		s->a[z++] = ft_atol(s->tmp[i], s);
		i++;
	}
}

void	initialize_stacks(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			s->a_size += ft_count_words(argv[i + 1], ' ');
		else
			s->a_size++;
		i++;
	}
	s->a = malloc(s->a_size * sizeof * s->a);
	if (s->a == NULL)
		free_and_exit_with_message(s, "Error\n");
	s->b = malloc(s->a_size * sizeof * s->b);
	if (s->b == NULL)
		free_and_exit_with_message(s, "Error\n");
}

void	create_index(t_stacks *s)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(s->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_message(s, "Error\n");
	i = -1;
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
	}
	i = s->a_size;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}

int	ft_atol(const char *nptr, t_stacks *s)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		res = res * 10 + (nptr[i++] - '0');
		if (res > 2147483647 || (res * sign) < -2147483648)
			free_and_exit_with_message(s, "Error\n");
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			free_and_exit_with_message(s, "Error\n");
	}
	return ((int)(res * sign));
}
