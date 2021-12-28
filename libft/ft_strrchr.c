/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:04:24 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/27 00:17:02 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	c = (unsigned char)c;
	p = (void *)0;
	while (*s)
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if (c == '\0')
		p = (char *)s;
	return (p);
}
