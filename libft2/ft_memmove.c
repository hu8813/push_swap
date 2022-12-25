/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:42 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/16 16:14:17 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_p;
	char	*src_p;
	size_t	i;

	i = 0;
	dst_p = (char *)dst;
	src_p = (char *)src;
	if (src == dst || !n)
		return (dst);
	if (src_p < dst_p)
	{
		while (++i <= n)
		{
			dst_p[n - i] = src_p[n - i];
		}
	}
	else
		while (n-- > 0)
			*dst_p++ = *src_p++;
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*p;
	char src[] = "hallaaaaaaaao";
	char dest[] = "test";
	p = ft_memmove(dest, src, 3);
	printf("%s", (unsigned char *)(p));
}
*/