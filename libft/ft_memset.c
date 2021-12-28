/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:03:17 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/24 00:03:17 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	c = (unsigned char)c;
	p = (unsigned char *)(s);
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
