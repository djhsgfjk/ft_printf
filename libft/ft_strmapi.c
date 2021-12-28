/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:04:13 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/25 14:26:49 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*new_str;

	if (s == (void *)0)
		return ((void *)0);
	len = ft_strlen(s);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == (void *)0)
		return (new_str);
	i = 0;
	while (i < len)
	{
		if ((*f) != 0)
			new_str[i] = (*f)(i, s[i]);
		else
			new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
