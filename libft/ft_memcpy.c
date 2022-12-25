/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:42 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/13 18:45:05 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	int		memccpy_length;
	char	str_dest[250];
	char	str_ft_dest[250];
	char	str1[12];

	printf("\n---memccpy---[string|memccpy|yours]\n");
	memccpy_length = 0;
	str_dest[250] = "";
	str_ft_dest[250] = "";
	str1[12] = "hello world";
	
	memccpy_length = 10;
		memcpy(str_dest, str1, memccpy_length);
		ft_memcpy(str_ft_dest, str1, memccpy_length);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", str1, str_dest, str_ft_dest);
		}
	printf("\n");
}
*/
