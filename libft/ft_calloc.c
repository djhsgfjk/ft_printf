/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:51:16 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/27 00:26:11 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned char	*s;
	int				i;
	int				len;

	if (((unsigned int)nmemb) * ((unsigned int)size) > 2147483647)
		return ((void *)0);
	len = (int)nmemb * (int)size;
	p = malloc(len);
	if (p == (void *)0 || len == 0)
		return (p);
	s = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
	return (p);
}
