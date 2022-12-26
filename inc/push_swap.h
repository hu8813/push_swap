/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:59 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/26 22:50:08 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	char	**tmparr;
	int		*a;
	int		*b;
	int		*index;
	int		a_size;
	int		b_size;
}			t_stacks;

int			main(int argc, char **argv);
void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		sort_three(t_stacks *s);
void		sort_four_to_five(t_stacks *s);
void		sort_using_radix_sort(t_stacks *s);
void		parse_numbers(int argc, char **argv, t_stacks *s);
void		create_index(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		free_and_exit_with_message(t_stacks *ptr, char *err);
void		check_if_sorted_or_has_duplicate(t_stacks *s);

#endif