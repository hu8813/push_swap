/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:41 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/24 22:47:05 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
#include <stdio.h>
int	main (void)
{
	char	c1;
	char	c2;

	c1 = 'a';
	c2 = '5';
	printf("char: %c is alpha or not: %d\n", c1, ft_isalpha(c1));
	printf("char: %c is alpha or not: %d\n", c2, ft_isalpha(c2));
}
*/
