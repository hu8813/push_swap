/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:30 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/25 16:08:24 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_if_sorted_or_has_dublicate(t_array_value *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr->a_size)
	{
		j = i + 1;
		while (j < arr->a_size)
		{
			if (arr->a[i] == arr->a[j])
				ft_exit(arr, "Error\n");
			j++;
		}
		i++;
	}
	i = 0;
	while (i < arr->a_size - 1)
	{
		if (arr->a[i] > arr->a[i + 1])
		{
			return ;
		}
		i++;
	}
	ft_exit(arr, NULL);
}

void	arg_count2(int argc, char **argv, t_array_value *arr)
{
	int	i;
	int	k;

	k = 0;
	while (argc-- > 1)
	{
		arr->k = ft_count_words(argv[arr->argv_indx + 1], ' ');
		if (arr->k == 1)
			arr->a[k] = ft_atoi(argv[arr->argv_indx + 1]);
		else if (arr->k > 1)
		{
			arr->tmparr = ft_split(argv[arr->argv_indx + 1], ' ');
			while (arr->k--)
				arr->a[k++] = ft_atoi(arr->tmparr[i++]);
			i = 0;
			while (arr->tmparr[i])
				free(arr->tmparr[i++]);
			free(arr->tmparr);
			i = 0;
			k--;
		}
		arr->argv_indx++;
		k++;
	}
	check_if_sorted_or_has_dublicate(arr);
}

void	arg_count(int argc, char **argv, t_array_value *arr)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	arr->a = 0;
	arr->tmparr = 0;
	arr->b = 0;
	arr->a_size = 0;
	arr->b_size = 0;
	arr->argv_indx = 0;
	while (argc--)
		k += ft_count_words(argv[i++], ' ');
	arr->a_size = k - 1;
	arr->k = k - 1;
}

void	make_index(t_array_value *arr)
{
	int	*new_a;
	int	i;
	int	j;
	int	k;
	int	min;

	new_a = malloc(sizeof(int) * arr->a_size);
	i = 0;
	while (i < arr->a_size)
	{
		j = 0;
		min = 2147483647;
		while (j < arr->a_size)
		{
			if (min > arr->a[j++])
			{
				min = arr->a[j - 1];
				k = j - 1;
			}
		}
		arr->a[k] = 2147483647;
		new_a[k] = i++;
	}
	free(arr->a);
	arr->a = new_a;
}

void	ft_exit(t_array_value *ptr, char *err)
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
