/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:30 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/31 05:20:00 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_stacks *s, int i)
{
	int	j;

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

void	parse_numbers(int argc, char **argv, t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	while (argc-- > 1 && argv[z + 1] != NULL)
	{
		if (argv[z + 1][0] == '\0')
			free_and_exit_with_message(s, "Error\n");
		if (ft_count_words(argv[z + 1], ' ') == 1)
			s->a[z] = ft_atol(argv[z + 1], s);
		else if (ft_count_words(argv[z + 1], ' ') > 1)
		{
			tmp = ft_split(argv[z + 1], ' ');
			i = 0;
			while (tmp[i])
				s->a[z++] = ft_atol(tmp[i++], s);
			i = 0;
			while (tmp[i])
				free(tmp[i++]);
			free(tmp);
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

void	create_index(t_stacks *s, long int *new_a)
{
	int			i;
	int			j;
	int			k;
	long int	min;

	i = s->a_size;
	while (i--)
		new_a[i] = s->a[i];
	i = 0;
	while (i < s->a_size)
	{
		j = 0;
		min = 2147483648;
		while (j < s->a_size)
		{
			if (new_a[j++] < min)
			{
				min = new_a[j - 1];
				k = j - 1;
			}
		}
		new_a[k] = 2147483648;
		s->a[k] = i++;
	}
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
		if (res > 2147483647 || (res * sign) < -2147483648)
			free_and_exit_with_message(s, "Error\n");
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			free_and_exit_with_message(s, "Error\n");
		res = res * 10 + (nptr[i++] - '0');
	}
	return ((int)(res * sign));
}
