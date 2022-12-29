/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:30 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/29 23:34:00 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_stacks *s)
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
			s->a[z] = ft_atol(argv[z + 1]);
		else if (j > 1)
		{
			tmp = ft_split(argv[z + 1], ' ');
			i = 0;
			while (j--)
				s->a[z++] = ft_atol(tmp[i++]);
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
		min = __INT_MAX__;
		while (j < s->a_size)
		{
			if (min == -1 || s->a[j++] < min)
			{
				min = s->a[j - 1];
				k = j - 1;
			}
		}
		s->a[k] = __INT_MAX__;
		new_a[k] = i++;
	}
	free(s->a);
	s->a = new_a;
}

int	ft_atol(const char *nptr)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + (nptr[i++] - '0');
	if (nptr[i] != 0 && (nptr[i] > '9' || nptr[i] < '0'))
		free_and_exit_with_message(NULL, "Error\n");
	if ((res * sign) < -2147483648 || (res * sign) > 2147483647)
		free_and_exit_with_message(NULL, "Error\n");
	return ((int)(res * sign));
}
