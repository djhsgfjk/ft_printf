/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:04:32 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/25 11:49:40 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*subs;

	if (s == (void *)0)
		return ((void *)0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else
		if (s_len - start < len)
			len = s_len - start;
	subs = malloc(len + 1);
	if (subs == (void *)0)
		return (subs);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
