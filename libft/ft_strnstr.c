/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:04:21 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/24 00:04:21 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*little))
		return ((char *)(big));
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j]
			&& little[j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(&big[i]));
		i++;
	}
	return ((void *)0);
}
