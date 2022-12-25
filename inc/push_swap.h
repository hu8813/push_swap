/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:59 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/25 16:07:36 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_array_value
{
	char	**tmparr;
	int		*a;
	int		*b;
	int		*index;
	int		a_size;
	int		b_size;
	int		k;
	int		argv_indx;
}			t_array_value;

int			main(int argc, char **argv);
void		rotate_ab(int *array, int size, char *direction, char *list);
void		swap_ab(char *s, int *array, int size);
void		push_ab(char *s, t_array_value *arr);
void		sort_3(t_array_value *arr);
void		sort_4_5(t_array_value *arr);
void		sort_radix(t_array_value *arr);
void		arg_count2(int argc, char **argv, t_array_value *arr);
void		make_index(t_array_value *arr);
void		arg_count(int argc, char **argv, t_array_value *arr);
void		ft_exit(t_array_value *ptr, char *err);

#endif