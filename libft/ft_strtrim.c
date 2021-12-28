/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:04:27 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/25 12:03:29 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_find_char_in_str(char const *s, char c)
{
	int	i;

	if (s == (void *)0)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*new_str;

	if (s1 == (void *)0)
		return ((void *)0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_find_char_in_str(set, s1[start]))
		start++;
	while (end > start && ft_find_char_in_str(set, s1[end]))
		end--;
	end++;
	new_str = malloc(end - start + 1);
	if (new_str == (void *)0)
		return (new_str);
	i = 0;
	while (i < end - start)
	{
		new_str[i] = s1[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
