/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:02:34 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/25 10:45:13 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_len(int n)
{
	int	i;
	int	len;

	if (n == 0)
		return (1);
	i = 1;
	len = 1;
	while (n / i >= 10 || n / i <= -10)
	{
		i *= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		sign;
	char	*str;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_count_len(n);
	if (sign < 0)
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (str == (void *)0)
		return (str);
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i--] = '0' + sign * (n % 10);
		n /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
