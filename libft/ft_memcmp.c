/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:42 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/15 16:59:12 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_p != *s2_p)
			return (*s1_p - *s2_p);
		s1_p++;
		s2_p++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[50] = "ayxbcdefgh";
	char	str2[50] = "zyxbcdefgh";
	int		dig1;
	int		dig2;

	dig1 = 4;
	dig2 = 2;
	printf("ft_cmp:%d\n", ft_memcmp(str1, str2, 0));
	printf("cmp:%d\n", memcmp(str1, str2, 0));
	printf("ft_cmp:%d\n", ft_memcmp(&dig1, &dig2, 4));
	printf("cmp:%d\n", memcmp(&dig1, &dig2, 4));
}
*/