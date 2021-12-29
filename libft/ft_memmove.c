/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:03:13 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/24 00:20:08 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_memmove_backwards(unsigned char *d,
									const unsigned char *s, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
}

static void	ft_memmove_forwards(unsigned char *d,
									const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)(src);
	d = (unsigned char *)(dest);
	if (d == (void *)0 && s == (void *)0)
		return ((void *)0);
	i = 0;
	while (i < n && &(d[0]) != &(s[i]))
		i++;
	if (i < n)
		ft_memmove_backwards(d, s, n);
	else
		ft_memmove_forwards(d, s, n);
	return (dest);
}
