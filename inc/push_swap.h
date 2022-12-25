/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:59 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/26 00:01:18 by huaydin          ###   ########.fr       */
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
	int		k;
	int		argv_indx;
}			t_stacks;

int			main(int argc, char **argv);
void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *s, int *array, int size);
void		push(char *s, t_stacks *arr);
void		sort_3(t_stacks *arr);
void		sort_4_5(t_stacks *arr);
void		sort_radix(t_stacks *arr);
void		arg_count2(int argc, char **argv, t_stacks *arr);
void		make_index(t_stacks *arr);
void		arg_count(int argc, char **argv, t_stacks *arr);
void		ft_exit(t_stacks *ptr, char *err);

#endif