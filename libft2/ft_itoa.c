/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:41 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/25 10:22:09 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizeofn(long m)
{
	int	i;

	i = 1;
	if (m < 0)
		i++;
	while (m > 9 || m < -9)
	{
		if (m < 0)
			m = -m;
		m = m / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	nlong;

	nlong = (long)n;
	len = ft_sizeofn(nlong);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (nlong < 0)
	{
		ptr[0] = '-';
		nlong = -nlong;
	}
	while (len-- >= 0 && nlong > 0 && ptr[len] != '-')
	{
		ptr[len] = nlong % 10 + '0';
		nlong = nlong / 10;
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-22));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1000034));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(3434));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648LL));
	return (1);
}
*/