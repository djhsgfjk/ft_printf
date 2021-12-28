/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:02:39 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/27 00:16:51 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	c = (unsigned char)c;
	p = (unsigned char *)(s);
	i = 0;
	while (i < n)
	{
		if (*p == c)
			return (p);
		p++;
		i++;
	}
	return ((void *)0);
}
